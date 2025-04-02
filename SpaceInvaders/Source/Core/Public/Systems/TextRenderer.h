// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include "Entity.h"
#include "System.h"


#include <ResourceManager.h>

class TextRenderer final : public System
{
public:
    explicit TextRenderer(ResourceManager& resourceManager);
    ~TextRenderer() override = default;
    void Render(std::vector<Entity> entities) const override;
    void Update(std::vector<Entity> entities, const TimeTicker& timeTicker, const GameState& gameState) override;
};

#endif
