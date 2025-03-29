// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <Logger.h>
#include <Screen.h>
#include <SFML/Window/Event.hpp>

class TitleScreen final : public Screen {
public:
    explicit TitleScreen(SpaceInvaders& game);

    void Update(const TimeTicker& timeTicker) override;
    void Render() const override;
    void Activate() override;
    void Shutdown() override;
    void HandleEvents(const std::optional<sf::Event>& event) override;

private:
    void OnKeyPressed(const sf::Event::KeyPressed& event) const;
    void OnMouseMove(const sf::Event::MouseMoved& event) const;
    void OnMousePressed(const sf::Event::MouseButtonPressed& event) const;

    const Logger _logger;
};

#endif
