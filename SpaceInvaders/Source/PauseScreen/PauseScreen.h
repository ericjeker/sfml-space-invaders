// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include "CommandRegistry.h"
#include "Screen.h"

#include "UI/UIManager.h"


class PauseScreen final : public Screen
{
public:
	explicit PauseScreen(SpaceInvaders& game);
	void CreateUI();

	void OnKeyPressed(sf::Event::KeyPressed key_pressed);
	void HandleEvents(const std::optional<sf::Event>& event) override;
	void Activate() override;
	void Update(const sf::Time& deltaTime) override;
	void Render() override;
	void Shutdown() override;

private:
	const Logger _logger;

	// Systems and Managers
	CommandRegistry _commandRegistry;
	std::unordered_map<std::string, int> _commands;

	UIManager _uiManager;

	// Rendering layers
	sf::ContextSettings _uiSettings;
	sf::RenderTexture _backgroundLayer;
	sf::RenderTexture _uiLayer;
};


#endif // PAUSESCREEN_H
