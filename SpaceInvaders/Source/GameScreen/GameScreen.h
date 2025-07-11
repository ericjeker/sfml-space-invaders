// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "CommandRegistry.h"
#include "Logger.h"
#include "Screen.h"
#include "SpaceInvaders.h"

#include "Collections/BulletCollection.h"
#include "Collections/EnemyCollection.h"
#include "Entities/PlayerState.h"

class UIManager;
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

private:
	void InitializeCommands(SpaceInvaders& game);
	void InitializeEnemies(const sf::RenderWindow& window);
	void InitializePlayer(const sf::RenderWindow& window);
	void InitializeRenderLayers(const sf::RenderWindow& window);
	void InitializeUI() const;

	// Rendering layers
	sf::ContextSettings _uiSettings;
	sf::RenderTexture _backgroundLayer;
	sf::RenderTexture _gameLayer;
	sf::RenderTexture _uiLayer;

	// Data & State
	PlayerState _playerState;
	EnemyCollection _enemies;
	BulletCollection _bullets;

	// Resources
	std::unique_ptr<sf::RectangleShape> _playerRectangle;
	std::unique_ptr<sf::RectangleShape> _enemyRectangle;
	std::unique_ptr<sf::RectangleShape> _bulletShape;

	// Commands Registry & locally available commands
	std::unique_ptr<CommandRegistry> _commandRegistry;
	std::unordered_map<std::string, int> _commands;

	// UI Manager holding the collection of UI Components
	std::unique_ptr<UIManager> _uiManager;
};

#endif
