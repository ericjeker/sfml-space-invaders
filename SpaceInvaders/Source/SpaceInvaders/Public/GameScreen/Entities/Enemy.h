// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

struct EnemyEntity : public Entity
{
    /** PhysicsComponent, CollisionComponent */
    sf::Vector2f position = sf::Vector2f(0.f, 0.f);
    sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);

    float damage = 10.0f;
};

#endif
