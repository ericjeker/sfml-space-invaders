// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "CommandRegistry.h"
#include "Logger.h"
#include "Screen.h"

#include "../../../Engine/Source/Core/Public/UI/UIManager.h"
#include "Managers/ParticleConstellationManager.h"

#include <SFML/Graphics/RenderTexture.hpp>

class TitleScreen final : public Screen
{
public:
    explicit TitleScreen(SpaceInvaders& game);

    void HandleEvents(const std::optional<sf::Event>& event) override;
    void Activate() override;
    void Update(const sf::Time& deltaTime) override;
    void Render() override;
    void Shutdown() override;

private:
    const Logger _logger;

    // Systems and Managers
    CommandRegistry _commandRegistry;
    UIManager _uiManager;
    ParticleConstellationManager _particleConstellation;

    // Rendering layers
    std::unique_ptr<sf::RenderTexture> _backgroundLayer;
    std::unique_ptr<sf::RenderTexture> _uiLayer;

    // Generate a Sprite from a RenderTexture
    // TODO: This could be reused by multiple screens
    sf::Sprite CreateRenderSprite(const sf::RenderTexture& renderTexture);

    // Accepted events
    void OnKeyPressed(const sf::Event::KeyPressed& event) const;
    void OnMouseMove(const sf::Event::MouseMoved& event) const;
    void OnMousePressed(const sf::Event::MouseButtonPressed& event) const;
};

#endif
