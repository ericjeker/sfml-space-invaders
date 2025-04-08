// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "ParticleCollection.h"

#include <TimeTicker.h>

#include <SFML/Graphics/RenderTexture.hpp>

class ParticleSystem {
public:
    ParticleSystem() = default;
    ~ParticleSystem() = default;
    void Update(const TimeTicker& timeTicker);
    void Render(sf::RenderTexture& renderTexture);
private:
    ParticleCollection _particles;
};

#endif
