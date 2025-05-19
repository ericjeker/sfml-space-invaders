// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

#include <SFML/System/Vector2.hpp>


struct EnemyCollection
{
    std::vector<sf::Vector2f> position{};
    std::vector<sf::Vector2f> velocity{};
    std::vector<sf::Vector2f> accelerations{};
    std::vector<float> damages{};
    std::vector<int> healths{};
};


#endif
