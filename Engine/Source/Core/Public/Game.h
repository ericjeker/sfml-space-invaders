// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef GAME_H
#define GAME_H

#include "Configuration.h"
#include "ResourceManager.h"
#include "ScreenManager.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
public:
    Game(const sf::RenderWindow& window, const Configuration& configuration);
    virtual ~Game() = default;

    // Called for starting the game after it's configured and initialized
    virtual void Run() = 0;
    // Exit the game and clean up the resources
    virtual void Exit() = 0;

    // Getters for the basic objects
    [[nodiscard]] const sf::RenderWindow& GetWindow() const;
    [[nodiscard]] const Configuration& GetConfiguration() const;

    // Getters for the managers and state services
    const ResourceManager& GetResourceManager() const;
    const ScreenManager& GetScreenManager() const;

protected:
    const Configuration _configuration;
    const sf::RenderWindow& _window;
    const ResourceManager _resourceManager;
    const ScreenManager _screenManager;
};

#endif
