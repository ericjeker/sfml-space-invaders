// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <Logger.h>
#include <Screen.h>

class TitleScreen final : public Screen {
public:
    explicit TitleScreen(SpaceInvaders& game);

    void Activate() override;
    void Update(const TimeTicker& timeTicker) override;
    void Render() const override;
    void Shutdown() override;
    void HandleEvents(const std::optional<sf::Event>& event) override;

private:
    const Logger _logger;

    // Rendering layers
    std::unique_ptr<sf::RenderTexture> _backgroundLayer;
    std::unique_ptr<sf::RenderTexture> _uiLayer;

    // Accepted events
    void OnKeyPressed(const sf::Event::KeyPressed& event) const;
    void OnMouseMove(const sf::Event::MouseMoved& event) const;
    void OnMousePressed(const sf::Event::MouseButtonPressed& event) const;
};

#endif
