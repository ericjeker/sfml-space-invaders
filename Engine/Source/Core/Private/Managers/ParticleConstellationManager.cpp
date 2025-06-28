// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Managers/ParticleConstellationManager.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>

#include <random>
#include <utility>

ParticleConstellationManager::ParticleConstellationManager(Configuration configuration, sf::Texture texture)
	: _configuration(std::move(configuration))
	, _logger("ParticleConstellationManager", LogLevel::Info)
	, _particleTexture(std::move(texture))
{
}

void ParticleConstellationManager::Initialize(const size_t n)
{
	// Initialize the RNG
	std::random_device device;
	std::mt19937 generator(device());

	// Reserve the pool size
	_particlePool.reserve(n);

	// Loop to create the particles
	for (size_t i = 0; i < n; ++i)
	{
		std::uniform_int_distribution dstWidth(1, static_cast<int>(_configuration.WindowSize.x));
		std::uniform_int_distribution dstHeight(1, static_cast<int>(_configuration.WindowSize.y));
		std::uniform_int_distribution dstVelocity(-100, 100);
		std::uniform_real_distribution dstScale(.05f, .1f);

		sf::Vector2f position{static_cast<float>(dstWidth(generator)), static_cast<float>(dstHeight(generator))};
		const sf::Vector2f velocity{static_cast<float>(dstVelocity(generator)),
									static_cast<float>(dstVelocity(generator))};
		const float scale = dstScale(generator);
		sf::Color color(255, 255, 255, std::ceil(255 * 0.6667));

		_particles.Add(position, color, scale, velocity, 10.f);

		// Generate the particles in the pool
		_particlePool.push_back(std::make_unique<sf::Sprite>(_particleTexture));
	}
}

void ParticleConstellationManager::Update(const sf::Time& deltaTime)
{
	_logger.Debug("Delta: " + std::to_string(deltaTime.asMilliseconds()));

	sf::Clock duration;
	duration.start();

	for (size_t i = 0; i < _particles.GetSize(); ++i)
	{
		_particles.positions[i].x += _particles.velocities[i].x * deltaTime.asSeconds();
		_particles.positions[i].y += _particles.velocities[i].y * deltaTime.asSeconds();

		ScreenWarp(_particles.positions[i], {_particleTexture.getSize().x * _particles.scales[i], _particleTexture.getSize().y * _particles.scales[i]});
	}

	// Updating (1000 particles): ~30us (0.2% of budget at 60 FPS)
	_logger.Debug("Updating: " + std::to_string(duration.getElapsedTime().asMicroseconds()) + "us");
}

void ParticleConstellationManager::Render(sf::RenderTexture& renderTexture) const
{
	sf::Clock duration;
	duration.start();

	for (size_t i = 0; i < _particles.GetSize(); ++i)
	{
		auto& sprite = _particlePool[i];
		sprite->setPosition(_particles.positions[i]);
		sprite->setScale({_particles.scales[i], _particles.scales[i]});
		sprite->setColor(_particles.colors[i]);
		renderTexture.draw(*sprite);
	}

	// Rendering (1000 particles): 11592us, without ObjectPool, (YOLO, CircleShape)
	// Rendering (1000 particles): 5414us, with basic ObjectPool (std::vector of shared_ptr, CircleShape)
	// Explore: VertexArray, Batch rendering, disable origin calculation, fragment shaders, etc.
	_logger.Debug("Rendering: " + std::to_string(duration.getElapsedTime().asMicroseconds()) + "us");
}

void ParticleConstellationManager::ScreenWarp(sf::Vector2f& OutPosition, const sf::Vector2f InSize)
{
	if (OutPosition.x + InSize.x < 0)
	{
		OutPosition.x = _configuration.WindowSize.x + InSize.x;
	}

	if (OutPosition.x - InSize.x > _configuration.WindowSize.x)
	{
		OutPosition.x = -InSize.x;
	}

	if (OutPosition.y + InSize.y < 0)
	{
		OutPosition.y = _configuration.WindowSize.y + InSize.y;
	}

	if (OutPosition.y - InSize.x > _configuration.WindowSize.y)
	{
		OutPosition.y = -InSize.x;
	}
}

void ParticleConstellationManager::SetParticleTexture(sf::Texture texture)
{
	_particleTexture = std::move(texture);
}
