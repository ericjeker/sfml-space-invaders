// Copyright (c) Eric Jeker. All Rights Reserved.

#include "UI/Text.h"

Text::Text(const std::shared_ptr<sf::Font>& font, const std::string& label, const unsigned int& size, const sf::Color& color)
	: _font(font)
	, _label(label)
	, _size(size)
	, _color(color)
	, _drawable(*font, label, size)
{
	_drawable.setFillColor(_color);
	_drawable.setString(_label);
	_drawable.setCharacterSize(_size);
	_drawable.setOrigin({_drawable.getGlobalBounds().size.x / 2, _drawable.getGlobalBounds().size.y / 2});
	_drawable.setPosition(_position);
}

void Text::Update(const sf::Time& deltaTime)
{
	_drawable.setPosition(_position);
}

void Text::Render(sf::RenderTexture& renderTexture) const
{
	if (_isHidden)
	{
		return;
	}

	renderTexture.draw(_drawable);
}

void Text::SetLabel(const std::string& label)
{
	_label = label;
}

void Text::TestHit(const sf::Vector2f& position)
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
