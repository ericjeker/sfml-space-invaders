// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/System/Vector2.hpp>

struct Ball
{
    sf::Vector2f position{0, 0};
    sf::Vector2f velocity{0, 0};
    float radius{10.0f};
};

class Ball : public Entity
{
};

#endif
