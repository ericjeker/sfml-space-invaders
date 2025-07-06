// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "CommandRegistry.h"
#include "Logger.h"
#include "Screen.h"

#include "Managers/ParticleConstellationManager.h"
#include "UI/UIManager.h"

#include <SFML/Graphics/RenderTexture.hpp>

class TitleScreen final : public Screen
{
public:
    explicit TitleScreen(SpaceInvaders& game);

	void HandleEvents(const std::optional<sf::Event>& event) override;
    void Activate() override;
    void Update(const sf::Time& deltaTime) override;
    void Render() override;
    void Shutdown() override;

	void CreateUI();

private:
	// Accepted events
	void OnKeyPressed(const sf::Event::KeyPressed& event);

	/** -----------------------------------------------------------------------
	 * Members
	 */

	const Logger _logger;

    // Systems and Managers
    CommandRegistry _commandRegistry;
	std::unordered_map<std::string, int> _commands;
    UIManager _uiManager;
    ParticleConstellationManager _particleConstellation;

    // Background layer
    sf::RenderTexture _backgroundLayer;

	// UI layer
	sf::ContextSettings _uiSettings;
    sf::RenderTexture _uiLayer;
};

#endif
