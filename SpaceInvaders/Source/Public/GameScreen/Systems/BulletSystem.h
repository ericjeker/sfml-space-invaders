// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef BULLETSYSTEM_H
#define BULLETSYSTEM_H

#include "Logger.h"
#include "Configuration.h"
#include "GameScreen/Collections/BulletCollection.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Time.hpp>


class BulletSystem
{
public:
    BulletSystem(const Configuration& configuration);
    ~BulletSystem() = default;

    void Initialize();
    // Update the bullet collection, handle collisions, and position.
    void Update(const sf::Time& deltaTime, BulletCollection& bullets);
    // Render the bullet collection on the render texture.
    void Render(sf::RenderTexture& renderTexture, const BulletCollection& bullets) const;

    // Create a new bullet at the specified position.
    void SpawnBullet(BulletCollection& bullets, const sf::Vector2f& position);

private:
    Logger _logger;
    const Configuration& _configuration;
    std::unique_ptr<sf::RectangleShape> _bulletShape;
};


#endif
