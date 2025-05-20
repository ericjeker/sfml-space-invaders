// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Game.h"

Game::Game(sf::RenderWindow& window, const Configuration& configuration)
    : _configuration(configuration)
    , _window(window)
    , _screenManager(configuration) {};

[[nodiscard]] sf::RenderWindow& Game::GetWindow()
{
    return _window;
};

[[nodiscard]] const Configuration& Game::GetConfiguration() const
{
    return _configuration;
};

ResourceManager& Game::GetResourceManager()
{
    return _resourceManager;
};

ScreenManager& Game::GetScreenManager()
{
    return _screenManager;
};

void Game::ScheduleCommand(const std::function<void()>& command)
{
    _deferredCommands.push(command);
};

void Game::ExecuteDeferredCommands()
{
    while (!_deferredCommands.empty())
    {
        _deferredCommands.front()();
        _deferredCommands.pop();
    }
};
