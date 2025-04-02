// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <GameState.h>
#include <TimeTicker.h>

#include <SFML/Graphics/RenderTexture.hpp>

class Component;
class Entity
{
public:
    virtual ~Entity() = default;
    virtual void Initialize() = 0;
    virtual void Update(const TimeTicker& timeTicker, const GameState& gameState) = 0;
    virtual void Render(sf::RenderTexture& texture) const  = 0;
    virtual void Destroy() = 0;

    virtual void AddComponent(std::unique_ptr<Component> component) = 0;
    // TODO: Use typeid to get the type of the component
    virtual void RemoveComponent(std::unique_ptr<Component> component) = 0;
private:
    // TODO: Use typeid to get the type of the component
    std::vector<std::unique_ptr<Component>> _components;
};

#endif
