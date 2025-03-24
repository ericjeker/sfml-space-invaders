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
    void HandleEvents() override;

private:
    void OnClose(const sf::Event::Closed&);
    void OnKeyPressed(const sf::Event::KeyPressed& keyPressed) const;

    const Logger _logger;
};

#endif
