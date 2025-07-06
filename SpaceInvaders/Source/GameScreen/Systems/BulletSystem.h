// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BULLETSYSTEM_H
#define BULLETSYSTEM_H

#include "GameScreen/Collections/BulletCollection.h"

#include <SFML/System/Vector2.hpp>

// Forward declarations
namespace sf
{
class Shape;
class RectangleShape;
class RenderTexture;
class Time;
} // namespace sf


namespace BulletSystem
{

void Initialize(BulletCollection& bullets);

// Update the bullet collection, handle collisions, and position.
void Update(const sf::Time& deltaTime, BulletCollection& bullets);

// Render the bullet collection on the render texture.
void Render(sf::RenderTexture& renderTexture, const BulletCollection& bullets, sf::Shape& shape);

// Create a new bullet at the specified position.
void SpawnBullet(BulletCollection& bullets, const sf::Vector2f& position);

}; // namespace BulletSystem


#endif
