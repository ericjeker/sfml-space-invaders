// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_H
#define GAME_H

#include "Configuration.h"
#include "GameScreen.h"
#include "GameState.h"
#include "Logger.h"
#include "ResourceManager.h"
#include "TimeTicker.h"

#include <SFML/Graphics.hpp>

class SpaceInvaders
{
public:
    explicit SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration);
    ~SpaceInvaders();
    void Run();
    sf::RenderWindow& GetWindow() const;
    const Configuration& GetConfiguration() const;
    ResourceManager& GetResourceManager();
    GameState& GetState();

private:
    const Configuration& _Configuration;
    const Logger _Logger;
    sf::RenderWindow& _Window;
    ResourceManager _ResourceManager;
    GameScreen _GameScreen;
    GameState _GameState;

private:
    void Update(const TimeTicker& timeTicker);
    void Render() const;
    void Shutdown();
    // Events
    void HandleEvents();
    void OnClose(const sf::Event::Closed&);
    void OnKeyPressed(const sf::Event::KeyPressed& keyPressed);
    void OnMouseMove(const sf::Event::KeyPressed& keyPressed);
};

#endif
