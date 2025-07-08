// Copyright (c) Eric Jeker. All Rights Reserved.

#include "UI/Button.h"

#include <string>

#include "SFML/Graphics/RectangleShape.hpp"

Button::Button(const std::shared_ptr<sf::Font>& font, const std::string& label, const unsigned int& fontSize,
			   const sf::Color& textColor, const int& commandId)
	: _text(*font, label, fontSize)
	, _outline(_text.getLocalBounds().size, 20, 132)
	, _font(font)
{
	SetCommand(commandId);

	_text.setFillColor(textColor);
	ResetLabelOrigin();
}

void Button::Update(const sf::Time& deltaTime)
{
	if (!_animator.IsEmpty())
	{
		_animator.Update(deltaTime);
	}
}

void Button::Render(sf::RenderTexture& renderTexture) const
{
	if (_isHidden)
	{
		return;
	}

	renderTexture.draw(_outline);
	renderTexture.draw(_text);
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

sf::Vector2f Button::GetSize() const
{
	return _outline.getSize();
}

void Button::SetSize(const sf::Vector2f& size)
{
	_outline.setSize(size);
}

void Button::SetScale(const sf::Vector2f& scale)
{
	_outline.setScale(scale);
	_text.setScale(scale);
}

void Button::SetOrigin(const sf::Vector2f& origin)
{
	_outline.setOrigin(origin);
}

void Button::SetPosition(const sf::Vector2f& position)
{
	UIComponent::SetPosition(position);
	_outline.setPosition(position);
	_text.setPosition(position);
}

void Button::SetOutlineFillColor(const sf::Color& color)
{
	_outline.setFillColor(color);
}

void Button::SetOutlineColor(const sf::Color& color)
{
	_outline.setOutlineColor(color);
}

void Button::SetOutlineThickness(const float& thickness)
{
	_outline.setOutlineThickness(thickness);
}

void Button::SetOutlineRadius(const float radius)
{
	_outline.setRadius(radius);
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

	if (_outline.getGlobalBounds().contains(position))
	{
		return true;
	}

	return false;
}

void Button::TestHit(const sf::Vector2f& position)
{
	if (!Contains(position))
	{
		if (_isHovered)
		{
			SetHovered(false);
			if (_onHoverExit)
			{
				_onHoverExit(*this);
			}
		}
	}
	else if (!_isHovered)
	{
		SetHovered(true);
		if (_onHover)
		{
			_onHover(*this);
		}
	}
}

void Button::SetOnHover(const Callback& callback)
{
	_onHover = callback;
}

void Button::SetOnHoverExit(const Callback& callback)
{
	_onHoverExit = callback;
}
