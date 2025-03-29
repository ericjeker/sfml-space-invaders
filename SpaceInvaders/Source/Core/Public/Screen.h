// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef SCREEN_H
#define SCREEN_H

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

private:
    SpaceInvaders& _game;
};

#endif
