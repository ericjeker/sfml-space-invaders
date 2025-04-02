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

    // Getters
    // TODO: make them const
    sf::RenderWindow& GetWindow() const;
    const Configuration& GetConfiguration() const;
    ResourceManager& GetResourceManager();
    ScreenManager& GetScreenManager();
    GameState& GetState();

private:
    const Logger _logger;
    const Configuration& _configuration;

    // SFML Window
    sf::RenderWindow& _window;

    // Managers and Services
    ResourceManager _resourceManager;
    ScreenManager _screenManager;
    GameState _gameState;

    // Game Loop related
    void Update(const TimeTicker& timeTicker) const;
    void Render() const;

    // Events
    void HandleEvents(const std::optional<sf::Event>& event);

    // Global Game Events related to the Window
    void OnClose();
    void OnFocusLost();
    void OnFocusGained();
};

#endif
