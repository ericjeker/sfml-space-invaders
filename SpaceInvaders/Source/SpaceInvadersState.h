// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef SPACEINVADERSSTATE_H
#define SPACEINVADERSSTATE_H

#include "GameScreen/Collections/BulletCollection.h"
#include "GameScreen/Collections/EnemyCollection.h"
#include "GameScreen/Entities/PlayerState.h"

#include <SFML/System/Vector2.hpp>

/**
 * GameState is a global state to manage the application's state.
 */
struct SpaceInvadersState
{
    // Mouse State
    sf::Vector2f mousePos = sf::Vector2f(-1.f, -1.f);

    // Game
    int score = 0;
    bool isGameOver = false;
    bool isPaused = false;

    // Player state
    PlayerState player;

    // Entity Collections, Enemy and Bullet
    BulletCollection bullets;
    EnemyCollection enemies;
};

#endif
