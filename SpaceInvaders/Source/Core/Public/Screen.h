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

    // Handling events by screen
    virtual void HandleEvents(const std::optional<sf::Event>& event) = 0;
    // Usual game loop element
    virtual void Update(const sf::Time& deltaTime) = 0;
    virtual void Render() = 0;
    // Triggered when the screen is activated
    virtual void Activate() = 0;
    // The screen is shut down, clean-up the mess it made
    virtual void Shutdown() = 0;

    // TODO: This is in Core but not reusable. Replace this with a generic Game class
    [[nodiscard]] SpaceInvaders& GetGame() const;
private:
    SpaceInvaders& _game;
};

#endif
