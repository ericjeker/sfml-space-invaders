// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "Logger.h"
#include "Screen.h"
#include "TimeTicker.h"

#include <SFML/Graphics.hpp>

/** Forward declarations */
class SpaceInvaders;

class GameScreen : public Screen
{
public:
    GameScreen(SpaceInvaders& game);
    ~GameScreen() override = default;
    void Activate() override;
    void Shutdown() override;
    /**
     * Updates the game screen state.
     * @param {TimeTicker} timeTicker - The time information
     */
    void Update(const TimeTicker& timeTicker) override;
    void Render() const override;

private:
    Logger _logger;

private:
    sf::CircleShape _Circle;
};

#endif
