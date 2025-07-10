// Copyright (c) Eric Jeker. All Rights Reserved.

#include "EnemySystem.h"

#include "Logger.h"

#include "GameScreen/Collections/EnemyCollection.h"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Time.hpp>


void EnemySystem::Update(sf::Time deltaTime, EnemyCollection& enemies)
{
	// TODO: implement
}

void EnemySystem::Render(sf::RenderTexture& renderTexture, const EnemyCollection& enemies, sf::Shape& shape)
{
	for (size_t i = 0; i < enemies.positions.size(); ++i)
	{
		shape.setPosition(enemies.positions[i]);
		renderTexture.draw(shape);
	}
}
