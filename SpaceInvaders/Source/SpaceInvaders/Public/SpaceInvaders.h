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
    GameState& GetState();

private:
    const Configuration& _configuration;
    const Logger _logger;
    sf::RenderWindow& _window;
    ResourceManager _resourceManager;
    ScreenManager _screenManager;
    GameState _gameState;

private:
    void Update(const TimeTicker& timeTicker) const;
    void Render() const;
    // Events
    void HandleEvents();
    void OnClose(const sf::Event::Closed&);
    void OnKeyPressed(const sf::Event::KeyPressed& keyPressed) const;
    void OnMouseMove(const sf::Event::KeyPressed& keyPressed) const;
};

#endif
