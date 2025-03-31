// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <SFML/System/Vector2.hpp>

struct PlayerPaddleEntity
{
    /** PhysicsComponent, CollisionComponent */
    sf::Vector2f position = sf::Vector2f(0.f, 0.f);
    sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);

    float health = 100.0f;
    float maxHealth = 100.0f;
    float damage = 10.0f;
};

struct BulletEntity
{
    /** PhysicsComponent, CollisionComponent */
    sf::Vector2f position = sf::Vector2f(0.f, 0.f);
    sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);

    float damage = 10.0f;
};

struct EnemyEntity
{
    /** PhysicsComponent, CollisionComponent */
    sf::Vector2f position = sf::Vector2f(0.f, 0.f);
    sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);

    float damage = 10.0f;
};

struct GameState
{
    sf::Vector2f mousePos = sf::Vector2f(-1.f, -1.f);
    bool isPaused = false;
    float score = 0;
    PlayerPaddleEntity playerPaddle{};

    /** Array of Structs */
    std::vector<BulletEntity> bullets{};

    /** Struct of Arrays */
};


#endif
