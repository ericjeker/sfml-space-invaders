// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/System/Vector2.hpp>

/**
 * GameState is a global state to manage the application's state.
 */
struct GameState
{
    sf::Vector2f mousePos = sf::Vector2f(-1.f, -1.f);
    bool isPaused = false;
};

#endif
