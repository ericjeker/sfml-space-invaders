// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef ENTITYRENDERABLE_H
#define ENTITYRENDERABLE_H

#include <SFML/Graphics/RenderTexture.hpp>

class RenderableEntity
{
public:
    virtual ~RenderableEntity() = default;
    virtual void Render(sf::RenderTexture& texture) const  = 0;
};

#endif
