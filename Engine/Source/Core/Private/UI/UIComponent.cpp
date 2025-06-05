// Copyright (c) Eric Jeker. All Rights Reserved.

#include "UI/UIComponent.h"

sf::FloatRect UIComponent::GetBounds() const
{
	return _bounds;
}

void UIComponent::SetBounds(const sf::FloatRect& bounds)
{
	_bounds = bounds;
}

sf::Vector2f UIComponent::GetPosition() const
{
	return _position;
}

void UIComponent::SetPosition(const sf::Vector2f& position)
{
	_position = position;
}

void UIComponent::SetDisabled(const bool& isDisabled)
{
	_isDisabled = isDisabled;
}

bool UIComponent::IsDisabled() const
{
	return _isDisabled;
}

void UIComponent::SetHidden(const bool& isHidden)
{
	_isHidden = isHidden;
}

bool UIComponent::IsHidden() const
{
	return _isHidden;
}

void UIComponent::SetHovered(const bool& isHovered)
{
	_isHovered = isHovered;
}

bool UIComponent::IsHovered() const
{
	return _isHovered;
}

int UIComponent::GetCommand() const
{
	return _commandId;
}

void UIComponent::SetCommand(const int& command)
{
	_commandId = command;
}

void UIComponent::TestHit(const sf::Vector2f& position)
{
}
