// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "ParticleSystem.h"

#include <random>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>

ParticleSystem::ParticleSystem(const Configuration& configuration) : _configuration(configuration), _logger("ParticleSystem", LogLevel::Info) {}

void ParticleSystem::Initialize(const size_t n)
{
    // Initialize the RNG
    std::random_device device;
    std::mt19937 generator(device());

    for (size_t i = 0; i < n; ++i)
    {
        std::uniform_int_distribution<int> dstWidth(1, _configuration.WindowSize.x);
        std::uniform_int_distribution<int> dstHeight(1, _configuration.WindowSize.y);
        std::uniform_int_distribution<int> dstVelocity(-100, 100);
        std::uniform_int_distribution<int> dstSize(2, 5);

        sf::Vector2f position{static_cast<float>(dstWidth(generator)), static_cast<float>(dstHeight(generator))};
        sf::Vector2f velocity{static_cast<float>(dstVelocity(generator)), static_cast<float>(dstVelocity(generator))};
        int size = dstSize(generator);
        sf::Color color(255, 255, 255, 128);

        _particles.Add(position, color, size, velocity, 10.f);

        auto circle = std::make_shared<sf::CircleShape>(10.f);
        circle->setRadius(size);
        circle->setFillColor(color);
        _particlePool.push_back(circle);
    }
}

void ParticleSystem::Update(const sf::Time& deltaTime)
{
    _logger.Debug("Delta: " + std::to_string(deltaTime.asMilliseconds()));

    sf::Clock duration;
    duration.start();

    for (size_t i = 0; i < _particles.GetSize(); ++i)
    {
        _particles.positions[i].x += _particles.velocities[i].x * deltaTime.asSeconds();
        _particles.positions[i].y += _particles.velocities[i].y * deltaTime.asSeconds();

        ScreenWarp(_particles.positions[i]);
    }

    // Updating (1000 particles): ~30us (0.2% of budget at 60 FPS)
    _logger.Debug("Updating: " + std::to_string(duration.getElapsedTime().asMicroseconds()) + "us");
}

void ParticleSystem::Render(sf::RenderTexture& renderTexture) const
{
    sf::Clock duration;
    duration.start();

    for (size_t i = 0; i < _particles.GetSize(); ++i)
    {
        auto& circle = _particlePool[i];
        circle->setPosition(_particles.positions[i]);
        renderTexture.draw(*circle);
    }

    // Rendering (1000 particles): 11592us, without ObjectPool, (YOLO, CircleShape)
    // Rendering (1000 particles): 5414us, with basic ObjectPool (std::vector of shared_ptr, CircleShape)
    // Explore: VertexArray, Batch rendering, disable origin calculation, fragment shaders, etc.
    _logger.Debug("Rendering: " + std::to_string(duration.getElapsedTime().asMicroseconds()) + "us");
}

void ParticleSystem::ScreenWarp(sf::Vector2f& position)
{
    if (position.x < 0)
    {
        position.x = _configuration.WindowSize.x;
    }

    if (position.x > _configuration.WindowSize.x)
    {
        position.x = 0;
    }

    if (position.y < 0)
    {
        position.y = _configuration.WindowSize.y;
    }

    if (position.y > _configuration.WindowSize.y)
    {
        position.y = 0;
    }
}
