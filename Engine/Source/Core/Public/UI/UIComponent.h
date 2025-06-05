// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/System/Time.hpp"


class UIComponent
{
public:
	virtual ~UIComponent() = default;

	virtual void Update(const sf::Time& deltaTime) = 0;
	virtual void Render(sf::RenderTexture& renderTexture) const = 0;

	// Getters and setters
	sf::FloatRect GetBounds() const;
	void SetBounds(const sf::FloatRect& bounds);

	sf::Vector2f GetPosition() const;
	void SetPosition(const sf::Vector2f& position);

	void SetDisabled(const bool& isDisabled);
	bool IsDisabled() const;
	void SetHidden(const bool& isHidden);
	bool IsHidden() const;
	void SetHovered(const bool& isHovered);
	bool IsHovered() const;

	int GetCommand() const;
	void SetCommand(const int& command);

	// Test the hit of the mouse on the component
	virtual void TestHit(const sf::Vector2f& position);

protected:
	sf::Vector2f _position;
	sf::FloatRect _bounds;

	bool _isHidden = false;
	bool _isHovered = false;
	bool _isDisabled = false;

	int _commandId = 0;
};


#endif // UICOMPONENT_H
