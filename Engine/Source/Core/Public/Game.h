// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef GAME_H
#define GAME_H

#include "Configuration.h"
#include "ResourceManager.h"
#include "ScreenManager.h"

#include <queue>

#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
public:
    Game(sf::RenderWindow& window, const Configuration& configuration);
    virtual ~Game() = default;

    // Called for starting the game after it's configured and initialized
    virtual void Run() = 0;
    // Exit the game and clean up the resources
    virtual void Exit() = 0;

    // Getters for the basic objects
    [[nodiscard]] sf::RenderWindow& GetWindow();
    [[nodiscard]] const Configuration& GetConfiguration() const;

    // Getters for the managers and state services
    ResourceManager& GetResourceManager();
    ScreenManager& GetScreenManager();

    void ScheduleCommand(const std::function<void()>& command);
    void ExecuteDeferredCommands();

protected:
    const Configuration _configuration;
    sf::RenderWindow& _window;
    ResourceManager _resourceManager;
    ScreenManager _screenManager;

    std::queue<std::function<void()>> _deferredCommands;
};

#endif
