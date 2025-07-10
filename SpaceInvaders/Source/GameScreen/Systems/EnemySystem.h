// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "GameScreen/Collections/EnemyCollection.h"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>


namespace EnemySystem
{

constexpr float ScreenPadding = 100.f;

float LeftMostPosition(const EnemyCollection& enemies);
float RightMostPosition(const EnemyCollection& enemies);

void Update(sf::Time deltaTime, EnemyCollection& enemies);
void Render(sf::RenderTexture& renderTexture, const EnemyCollection& enemies, sf::RectangleShape& shape);


}; // namespace EnemySystem


#endif // ENEMYSYSTEM_H
