// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/System/Vector2.hpp>


struct Player
{
    sf::Vector2f position{0.f, 0.f};
    sf::Vector2f velocity{0.f, 0.f};
    int health{0};
};


#endif
