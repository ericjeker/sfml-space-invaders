// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "TextRenderer.h"

#include "Entity.h"

#include <GameState.h>
#include <Text.h>
#include <TimeTicker.h>

void TextRenderer::Render(std::vector<Entity> entities) const
{
    // TODO: Loop the entities and render the TextComponents
    for (const auto& entity : entities)
    {
        // Render if TextComponent is available
        if (auto textComponent = std::dynamic_pointer_cast<TextComponent>(entity.GetComponent("TextComponent")))
        {

        }
    }
}

void TextRenderer::Update(std::vector<Entity> entities, const TimeTicker& timeTicker, const GameState& gameState)
{
    // Not Implemented
}