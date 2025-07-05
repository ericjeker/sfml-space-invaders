// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef BULLETSPAWNERSYSTEM_H
#define BULLETSPAWNERSYSTEM_H

#include "GameScreen/Collections/BulletCollection.h"

#include <SFML/System/Time.hpp>


class BulletSpawnerSystem
{
public:
	BulletSpawnerSystem();
	~BulletSpawnerSystem() = default;

	// Update the bullet collection, handle collisions, and position.
	void Update(const sf::Time& deltaTime, /*CommandBuffer& commandBuffer, */ BulletCollection& bullets);

	// Create a new bullet at the specified position.
	void SpawnBullet(BulletCollection& bullets, const sf::Vector2f& position);
};


#endif // BULLETSPAWNERSYSTEM_H
