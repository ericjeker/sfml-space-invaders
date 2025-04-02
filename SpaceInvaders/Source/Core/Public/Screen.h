// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include "Entity.h"
#include "RenderableEntity.h"

#include <TimeTicker.h>
#include <SFML/Window/Event.hpp>

class SpaceInvaders;
class Screen
{
public:
    explicit Screen(SpaceInvaders& game);
    virtual ~Screen() = default;

    virtual void Update(const TimeTicker& timeTicker) = 0;
    virtual void Render() const = 0;
    virtual void Activate() = 0;
    virtual void Shutdown() = 0;
    virtual void HandleEvents(const std::optional<sf::Event>& event) = 0;

    // TODO: Replace this with a generic Game class
    SpaceInvaders& GetGame() const;

protected:
    void AddEntity(const std::shared_ptr<Entity>& entity);
    std::vector<std::shared_ptr<Entity>> _entities;
    void AddSystem(const std::shared_ptr<System>& system);
    std::vector<std::shared_ptr<System>> _systems;

private:
    SpaceInvaders& _game;
};

#endif
