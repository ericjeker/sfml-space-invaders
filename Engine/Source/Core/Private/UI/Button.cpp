// Copyright (c) Eric Jeker. All Rights Reserved.

#include "UI/Button.h"

#include <cmath>
#include <iostream>
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

void Button::SetSize(const sf::Vector2f& size)
{
	_outline.setSize(size);
}

void Button::SetPosition(const sf::Vector2f& position)
{
	UIComponent::SetPosition(position);
	_outline.setPosition(position);
	_text.setPosition({position.x + _outline.getSize().x / 2.f, position.y + _outline.getSize().y / 2.f});
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

void Button::SetOutlineRadius(const float& radius)
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

	if (position.x < _position.x || position.x > _position.x + _outline.getSize().x || position.y < _position.y ||
		position.y > _position.y + _outline.getSize().y)
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
