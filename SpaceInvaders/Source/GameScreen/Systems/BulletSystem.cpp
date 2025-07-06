// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "GameScreen/Systems/BulletSystem.h"

#include "GameScreen/Collections/BulletCollection.h"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Time.hpp>

void BulletSystem::Initialize(BulletCollection& bullets)
{

}


void BulletSystem::Update(const sf::Time& deltaTime, BulletCollection& bullets)
{
	for (size_t i = 0; i < bullets.positions.size(); ++i)
	{
		const float delta = deltaTime.asSeconds();
		bullets.positions[i] += bullets.velocities[i] * delta;
	}
}

void BulletSystem::Render(sf::RenderTexture& renderTexture, const BulletCollection& bullets, sf::Shape& shape)
{
	// TODO: will have to create an object pool
	for (size_t i = 0; i < bullets.positions.size(); ++i)
	{
		shape.setPosition(bullets.positions[i]);
		renderTexture.draw(shape);
	}
}

void BulletSystem::SpawnBullet(BulletCollection& bullets, const sf::Vector2f& position)
{
	bullets.positions.push_back(position);
	bullets.velocities.push_back(sf::Vector2f(0.f, -750.f));
	bullets.accelerations.push_back(sf::Vector2f(0.f, 1000.f));
	bullets.damages.push_back(10);
}
