// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Game.h"

Game::Game(const sf::RenderWindow& window, const Configuration& configuration)
    : _window(window)
    , _configuration(configuration)
    , _screenManager(configuration)
{
}

[[nodiscard]] const sf::RenderWindow& Game::GetWindow() const
{
    return _window;
};

[[nodiscard]] const Configuration& Game::GetConfiguration() const
{
    return _configuration;
};

const ResourceManager& Game::GetResourceManager() const
{
    return _resourceManager;
};

const ScreenManager& Game::GetScreenManager() const
{
    return _screenManager;
};
