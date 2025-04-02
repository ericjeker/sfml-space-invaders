// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

#include <SFML/System/Vector2.hpp>

struct Bullet
{
    /** PhysicsComponent, CollisionComponent */
    sf::Vector2f position = sf::Vector2f(0.f, 0.f);
    sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);

    float damage = 10.0f;
};

class Bullet : public Entity
{

};

#endif
