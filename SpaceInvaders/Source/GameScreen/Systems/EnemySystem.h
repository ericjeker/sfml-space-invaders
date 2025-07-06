// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "GameScreen/Collections/EnemyCollection.h"


namespace sf
{
class RenderTexture;
class Time;
}

namespace EnemySystem
{
void Initialize(EnemyCollection& enemies);
void Update(sf::Time deltaTime, EnemyCollection& enemies);
void Render(sf::RenderTexture& renderTexture, const EnemyCollection& enemies);
};


#endif // ENEMYSYSTEM_H
