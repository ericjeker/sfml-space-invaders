// Copyright (c) Eric Jeker. All Rights Reserved.

#include "UI/Button.h"

#include <string>

Button::Button(const std::shared_ptr<sf::Font>& font, const std::string& label, const unsigned int& fontSize,
			   const int& commandId)
	: _label(label)
	, _fontSize(fontSize)
	, _text(*font, label, fontSize)
{
	SetCommand(commandId);

	_drawable.setFillColor(sf::Color::Transparent);
	// _drawable.setOutlineColor(sf::Color::White);
	// _drawable.setOutlineThickness(6.f);

	_text.setFillColor(sf::Color::White);
	_text.setOrigin({_text.getGlobalBounds().size.x / 2, _text.getGlobalBounds().size.y / 2});
}

void Button::Update(const sf::Time& deltaTime)
{
	_drawable.setPosition(_position);
	_text.setPosition({_position.x + _drawable.getGlobalBounds().size.x / 2, _position.y + _drawable.getGlobalBounds().size.y / 2});
}

void Button::Render(sf::RenderTexture& renderTexture) const
{
	if (_isHidden)
	{
		return;
	}

	renderTexture.draw(_drawable);
	renderTexture.draw(_text);

	// Draw a debuggings rectangle if the button is hovered
	if (_debug && _isHovered)
	{
		sf::RectangleShape rect;
		rect.setSize({_drawable.getGlobalBounds().size.x, _drawable.getGlobalBounds().size.y});
		rect.setPosition({_drawable.getPosition().x, _drawable.getPosition().y});
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(1.f);

		renderTexture.draw(rect);
	}
}

void Button::SetLabel(const std::string& label)
{
	_label = label;
}

void Button::SetSize(sf::Vector2f size)
{
	_size = size;
	_drawable.setSize(size);
}

void Button::TestHit(const sf::Vector2f& position)
{
	if (_drawable.getGlobalBounds().contains(position))
	{
		SetHovered(true);
	}
	else
	{
		SetHovered(false);
	}
}
