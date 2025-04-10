// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_H
#define GAME_H

#include "Configuration.h"
#include "GameState.h"
#include "Logger.h"
#include "ResourceManager.h"
#include "ScreenManager.h"
#include "TimeTicker.h"

#include <SFML/Graphics.hpp>

class SpaceInvaders
{
public:
    explicit SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration);
    ~SpaceInvaders() = default;

    // Called for starting the game after it's configured and initialized
    void Run();
    // Exit the game and clean-up the resources
    void Exit();

    // Getters for the basic objects
    sf::RenderWindow& GetWindow() const;
    const Configuration& GetConfiguration() const;

    // Getters for the managers and state services
    ResourceManager& GetResourceManager();
    ScreenManager& GetScreenManager();

    // Getters  for the game state
    GameState& GetState();

private:
    const Logger _logger;
    const Configuration& _configuration;

    // SFML Window
    sf::RenderWindow& _window;

    // Managers and State Services
    ResourceManager _resourceManager;
    ScreenManager _screenManager;
    GameState _gameState;

    // Events handling first
    void HandleEvents(const std::optional<sf::Event>& event);

    // Game Loop related second
    void Update(const sf::Time& deltaTime) const;
    void Render() const;

    // Game Events related to the Window
    void OnClose();
    void OnFocusLost();
    void OnFocusGained();
    void OnResize();
};

#endif
