// Copyright (c) Eric Jeker. All Rights Reserved.

#include "UI/Button.h"

#include <cmath>
#include <string>

Button::Button(const std::shared_ptr<sf::Font>& font, const std::string& label, const unsigned int& fontSize,
			   const sf::Color& textColor, const int& commandId)
	: _text(*font, label, fontSize)
	, _vertices(sf::PrimitiveType::TriangleFan)
{
	SetCommand(commandId);

	_vertices.resize(_resolution);
	_text.setFillColor(textColor);

	ResetLabelOrigin();
}

void Button::Update(const sf::Time& deltaTime)
{
}

void Button::Render(sf::RenderTexture& renderTexture) const
{
	if (_isHidden)
	{
		return;
	}

	renderTexture.draw(_vertices);
	renderTexture.draw(_text);

	// Draw a debuggings rectangle if the button is hovered
	if (_debug && IsHovered())
	{
		sf::RectangleShape rect;
		rect.setSize(_size);
		rect.setPosition(_position);
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(1.f);

		sf::RectangleShape rectText;
		rectText.setSize(_text.getGlobalBounds().size);
		rectText.setPosition(_text.getPosition());
		rectText.setFillColor(sf::Color::Transparent);
		rectText.setOutlineColor(sf::Color::Blue);
		rectText.setOutlineThickness(1.f);
		rectText.setOrigin(_text.getGlobalBounds().size / 2.f);

		renderTexture.draw(rect);
		renderTexture.draw(rectText);
	}
}

void Button::CreateOutline()
{
	constexpr float pi = std::numbers::pi_v<float>;

	// Insert a circle in the VertexArray
	for (size_t i = 0; i < _resolution; ++i)
	{
		const float angle = 2 * pi / _resolution * i;
		const auto x = std::cos(angle);
		const auto y = std::sin(angle);
		sf::Vector2f position = _position;

		// Calculate in which quadrant we are, SFML use a Y-down coordinate system
		if (x >= 0 && y < 0) // NE
		{
			position.x += _size.x - _radius;
			position.y += _radius;
		}
		else if (x < 0 && y <= 0) // NW
		{
			position.x += _radius;
			position.y += _radius;
		}
		else if (x <= 0 && y > 0) // SW
		{
			position.x += _radius;
			position.y += _size.y - _radius;
		}
		else if (x > 0 && y >= 0) // SE
		{
			position.x += _size.x - _radius;
			position.y += _size.y - _radius;
		}

		_vertices[i] = sf::Vertex({x * _radius + position.x, y * _radius + position.y}, _color);
	}
}

void Button::SetLabel(const std::string& label)
{
	_text.setString(label);
	ResetLabelOrigin();
}

void Button::ResetLabelOrigin()
{
	const auto bounds = _text.getLocalBounds();
	_text.setOrigin({bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f});
}

void Button::SetSize(const sf::Vector2f& size)
{
	_size = size;
	CreateOutline();
}

void Button::SetPosition(const sf::Vector2f& position)
{
	UIComponent::SetPosition(position);

	_text.setPosition({position.x + _size.x / 2.f, position.y + _size.y / 2.f});

	CreateOutline();
}

void Button::SetOutlineColor(const sf::Color& color)
{
	_color = color;
	CreateOutline();
}

void Button::SetOutlineThickness(const float& thickness)
{
	_thickness = thickness;
	CreateOutline();
}

void Button::SetOutlineRadius(const float& radius)
{
	_radius = radius;
	CreateOutline();
}

bool Button::Contains(const sf::Vector2f& position) const
{
	if (_isDisabled)
	{
		return false;
	}

	if (_isHidden)
	{
		return false;
	}

	if (position.x < _position.x || position.x > _position.x + _size.x || position.y < _position.y ||
		position.y > _position.y + _size.y)
	{
		return false;
	}

	return true;
}

void Button::TestHit(const sf::Vector2f& position)
{
	if (Contains(position))
	{
		SetHovered(true);
	}
	else
	{
		SetHovered(false);
	}
}
