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
    void Run();
    sf::RenderWindow& GetWindow() const;
    const Configuration& GetConfiguration() const;
    ResourceManager& GetResourceManager();
    ScreenManager& GetScreenManager();
    GameState& GetState();
    void Exit();

private:
    const Configuration& _configuration;
    const Logger _logger;

    // SFML Window
    sf::RenderWindow& _window;

    // Managers and Services
    ResourceManager _resourceManager;
    ScreenManager _screenManager;
    GameState _gameState;

private:
    void Update(const TimeTicker& timeTicker) const;
    void Render() const;
    // Events
    void HandleEvents(const std::optional<sf::Event>& event);

    void OnClose();
    void OnFocusLost();
    void OnFocusGained();
};

#endif
