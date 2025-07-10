// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

#include <SFML/System/Vector2.hpp>


struct EnemyCollection
{
	enum class Direction
	{
		Left,
		Right
	};

	Direction direction = Direction::Left;
	sf::Vector2f speed = sf::Vector2f(500.f, 1000.f);

    std::vector<sf::Vector2f> positions{};
    std::vector<sf::Vector2f> velocities{};
    std::vector<sf::Vector2f> accelerations{};
    std::vector<float> damages{};
    std::vector<int> healths{};
};


#endif
