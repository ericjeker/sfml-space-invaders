// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "Logger.h"
#include "TimeTicker.h"

#include <SFML/Graphics.hpp>

/** Forward declarations */
class SpaceInvaders;

class GameScreen
{
public:
    explicit GameScreen(SpaceInvaders& game);
    ~GameScreen();
    void Activate() const;
    void Shutdown() const;
    /**
     * Updates the game screen state.
     * @param {TimeTicker} timeTicker - The time information
     */
    void Update(const TimeTicker& timeTicker);
    void Render() const;

private:
    Logger _Logger;
    SpaceInvaders& _Game;

private:
    sf::CircleShape _Circle;
};

#endif
