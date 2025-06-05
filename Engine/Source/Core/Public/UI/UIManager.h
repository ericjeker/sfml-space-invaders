// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "CommandRegistry.h"
#include "ResourceManager.h"
#include "UIComponent.h"

#include "Collections/GUI/ButtonCollection.h"
#include "Collections/GUI/TextCollection.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

/**
 * The UIManager take care of GUI elements and their interaction. Accepting events and checking for hits
 * on the elements, modifying their state. The UIManager is also responsible for rendering these elements.
 *
 * But let's KISS for now.
 */
class UIManager
{
public:
	explicit UIManager(CommandRegistry& commandRegistry);
	~UIManager() = default;

	void Update(const sf::Time& deltaTime) const;
	void Render(sf::RenderTexture& renderTexture) const;

	// Components management
	void AddComponent(std::unique_ptr<UIComponent> component);
	void ClearComponents();

	// Potential future events I will handle
	void HandleEvents(const std::optional<sf::Event>& event) const;
	void OnMouseMove(const sf::Event::MouseMoved& event) const;
	void OnMousePressed(const sf::Event::MouseButtonPressed& event) const;

private:
	// We need the resource manager to load images and fonts
	CommandRegistry& _commandRegistry;

	// The actual sf::Drawable elements
	std::vector<std::shared_ptr<UIComponent>> _components;
};

#endif
