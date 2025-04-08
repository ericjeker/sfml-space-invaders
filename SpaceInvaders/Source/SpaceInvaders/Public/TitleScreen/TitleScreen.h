// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <GUIManager.h>
#include <Logger.h>
#include <ParticleSystem.h>
#include <Screen.h>

#include <SFML/Graphics/RenderTexture.hpp>

class TitleScreen final : public Screen
{
public:
    explicit TitleScreen(SpaceInvaders& game);

    void Activate() override;
    void Update(const TimeTicker& timeTicker) override;
    void Render() override;
    void Shutdown() override;
    void HandleEvents(const std::optional<sf::Event>& event) override;

private:
    const Logger _logger;

    GUIManager _guiManager;
    ParticleSystem _particleSystem;

    // Rendering layers
    std::unique_ptr<sf::RenderTexture> _backgroundLayer;
    std::unique_ptr<sf::RenderTexture> _uiLayer;

    // Generate a Sprite from a RenderTexture
    sf::Sprite CreateRenderSprite(const sf::RenderTexture& renderTexture);

    // Accepted events
    void OnKeyPressed(const sf::Event::KeyPressed& event) const;
    void OnMouseMove(const sf::Event::MouseMoved& event) const;
    void OnMousePressed(const sf::Event::MouseButtonPressed& event) const;
};

#endif
