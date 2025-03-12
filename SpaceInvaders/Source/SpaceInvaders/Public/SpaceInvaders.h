// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_H
#define GAME_H

#include <Configuration.h>
#include <SFML/Graphics.hpp>

#include "Logger.h"
#include "TimeTicker.h"
#include "GameScreen.h"
#include "GameState.h"

class SpaceInvaders
{
public:
    explicit SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration);
    ~SpaceInvaders();
    void Run();
    sf::RenderWindow& GetWindow() const;
    GameState& GetState();
    const Configuration& GetConfiguration() const;

private:
    sf::RenderWindow& _Window;
    const Configuration& _Configuration;
    Logger _Logger;
    GameScreen _GameScreen;
    GameState _GameState;

private:
    void Update(const TimeTicker& timeTicker);
    void Render() const;
    // Events
    void HandleEvents();
    void OnClose(const sf::Event::Closed&) const;
    void OnKeyPressed(const sf::Event::KeyPressed& keyPressed) const;
    void OnMouseMove(const sf::Event::KeyPressed& keyPressed) const;
};

#endif
