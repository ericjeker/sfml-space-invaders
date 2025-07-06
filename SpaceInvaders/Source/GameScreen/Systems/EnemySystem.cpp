// Copyright (c) Eric Jeker. All Rights Reserved.

#include "GameScreen/Systems/EnemySystem.h"

#include "GameScreen/Collections/EnemyCollection.h"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Time.hpp>

namespace
{
}

void Initialize(EnemyCollection& enemies)
{
	return;
}

void Update(sf::Time deltaTime, EnemyCollection& enemies)
{
	return;
}

void Render(sf::RenderTexture& renderTexture, const EnemyCollection& enemies, sf::Shape& shape)
{
	for (size_t i = 0; i < enemies.positions.size(); ++i)
	{
		shape.setPosition(enemies.positions[i]);
		renderTexture.draw(shape);
	}
}
