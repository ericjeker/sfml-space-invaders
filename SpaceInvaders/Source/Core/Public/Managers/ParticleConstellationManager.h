// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PARTICLECONSTELLATIONMANAGER_H
#define PARTICLECONSTELLATIONMANAGER_H

#include "ParticleCollection.h"

#include <Configuration.h>
#include <TimeTicker.h>
#include <SFML/Graphics/CircleShape.hpp>

#include <SFML/Graphics/RenderTexture.hpp>

class ParticleConstellationManager {
public:
    explicit ParticleConstellationManager(const Configuration& configuration);
    ~ParticleConstellationManager() = default;
    void Update(const sf::Time& deltaTime);
    void Render(sf::RenderTexture& renderTexture) const;
    void ScreenWarp(sf::Vector2f& position);
    void Initialize(size_t n);

private:
    int _accumulator = 0;
    const int _timeStep = 1000 / 60;

    Configuration _configuration;
    Logger _logger;
    ParticleCollection _particles;
    std::vector<std::shared_ptr<sf::CircleShape>> _particlePool;
};

#endif
