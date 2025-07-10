// Copyright (c) Eric Jeker. All Rights Reserved.

#include "EnemySystem.h"

#include "Configuration.h"

#include "GameScreen/Collections/EnemyCollection.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Time.hpp>

// TODO: LeftMost and RightMost are the same function with only one small difference
//   as a software engineer I should be able to make it one...
float EnemySystem::LeftMostPosition(const EnemyCollection& enemies)
{
	float leftMost = enemies.positions[0].x;

	for (size_t i = 1; i < enemies.positions.size(); ++i)
	{
		leftMost = std::min(leftMost, enemies.positions[i].x);
	}

	return leftMost;
}

float EnemySystem::RightMostPosition(const EnemyCollection& enemies)
{
	float leftMost = enemies.positions[0].x;

	for (size_t i = 1; i < enemies.positions.size(); ++i)
	{
		leftMost = std::max(leftMost, enemies.positions[i].x);
	}

	return leftMost;
}

void EnemySystem::Update(const sf::Time deltaTime, EnemyCollection& enemies)
{
	// Every cycle we have to move the enemy horde to the left or to the right
	enemies.direction == EnemyCollection::Direction::Left ? enemies.positions[0].x -= enemies.speed.x * deltaTime.asSeconds()
														  : enemies.positions[0].x += enemies.speed.x * deltaTime.asSeconds();

	// If the leftmost enemy touch the screen edge we revert the direction
	switch (enemies.direction)
	{
		case EnemyCollection::Direction::Left:
		{
			if (const float leftY = LeftMostPosition(enemies); leftY < ScreenPadding)
			{
				enemies.direction = EnemyCollection::Direction::Right;
			}
			break;
		}
		case EnemyCollection::Direction::Right:
		{
			if (const float rightY = RightMostPosition(enemies); rightY > Configuration::WindowSize.x - ScreenPadding)
			{
				enemies.direction = EnemyCollection::Direction::Left;
				// If the rightmost enemy touch the screen edge we move the horde down and revert the direction
				for (size_t i = 0; i < enemies.positions.size(); ++i)
				{
					enemies.positions[i].y += enemies.speed.y * deltaTime.asSeconds();
				}
			}
			break;
		}
	}

}

void EnemySystem::Render(sf::RenderTexture& renderTexture, const EnemyCollection& enemies, sf::RectangleShape& shape)
{
	for (size_t i = 0; i < enemies.positions.size(); ++i)
	{
		shape.setPosition(enemies.positions[i]);
		renderTexture.draw(shape);
	}
}
