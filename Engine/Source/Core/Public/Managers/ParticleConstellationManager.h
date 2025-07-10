// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PARTICLECONSTELLATIONMANAGER_H
#define PARTICLECONSTELLATIONMANAGER_H

#include "Collections/ParticleCollection.h"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

class ParticleConstellationManager
{
public:
	explicit ParticleConstellationManager(sf::Texture texture);
	~ParticleConstellationManager() = default;

	void Initialize(size_t n);
	void Update(const sf::Time& deltaTime);
	void Render(sf::RenderTexture& renderTexture) const;
	void ScreenWarp(sf::Vector2f& OutPosition, sf::Vector2f InSize);

	void SetParticleTexture(sf::Texture texture);

private:
	int _accumulator = 0;
	const int _timeStep = 1000 / 60;

	ParticleCollection _particles;
	std::vector<std::unique_ptr<sf::Sprite>> _particlePool;
	sf::Texture _particleTexture;
};

#endif
