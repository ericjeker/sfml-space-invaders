// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <vector>

#include <SFML/System/Vector2.hpp>

struct BulletCollection
{
    std::vector<sf::Vector2f> position{};
    std::vector<sf::Vector2f> velocity{};
    std::vector<sf::Vector2f> accelerations{};
    std::vector<int> damages{};
};

#endif
