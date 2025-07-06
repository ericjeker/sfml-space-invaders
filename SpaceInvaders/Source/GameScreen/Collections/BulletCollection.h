// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <vector>

#include <SFML/System/Vector2.hpp>

struct BulletCollection
{
    std::vector<sf::Vector2f> positions{};
    std::vector<sf::Vector2f> velocities{};
    std::vector<sf::Vector2f> accelerations{};
    std::vector<int> damages{};
};

#endif
