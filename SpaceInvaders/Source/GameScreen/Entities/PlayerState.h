// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/System/Vector2.hpp>


struct PlayerState
{
	sf::Vector2f position{0.f, 0.f};
	sf::Vector2f velocity{0.f, 0.f};

	// Current health
	int health = 100;

	// Cooldown between two bullet shot
	float cooldown = 0.f;		   // seconds
	float cooldownDuration = 0.5f; // seconds
};


#endif
