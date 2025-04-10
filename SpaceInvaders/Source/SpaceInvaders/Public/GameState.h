// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "ButtonCollection.h"
#include "Collections/BulletCollection.h"
#include "Collections/EnemyCollection.h"
#include "Entities/Player.h"


#include <SFML/System/Vector2.hpp>

/**
 * GameState is a global state to manage the application's state.
 */
struct GameState
{
    // Mouse State
    sf::Vector2f mousePos = sf::Vector2f(-1.f, -1.f);

    // Game
    int score = 0;
    bool isGameOver = false;
    bool isPaused = false;

    // Player state
    Player player;

    // Entity Collections, Enemy and Bullet
    BulletCollection bullets;
    EnemyCollection enemies;
};

#endif
