// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "CommandRegistry.h"
#include "Logger.h"
#include "Screen.h"
#include "SpaceInvaders.h"

#include "GameScreen/Systems/PlayerController.h"
#include "Systems/BulletSystem.h"

class GameScreen final : public Screen
{
public:
	explicit GameScreen(SpaceInvaders& game);
	~GameScreen() override = default;

    void Activate() override;
	void Shutdown() override;
	void HandleEvents(const std::optional<sf::Event>& event) override;

	void Update(const sf::Time& deltaTime) override;
	void Render() override;

    void CreateUI();

private:
	Logger _logger;

	// Rendering layers
	sf::ContextSettings _uiSettings;
	sf::RenderTexture _backgroundLayer;
	sf::RenderTexture _gameLayer;
	sf::RenderTexture _uiLayer;

	// Resources


	// Systems
	PlayerController _playerController;
	BulletSystem _bulletSystem;
	std::unique_ptr<CommandRegistry> _commandRegistry;
};

#endif
