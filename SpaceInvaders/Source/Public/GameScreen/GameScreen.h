// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "SpaceInvaders.h"
#include "Systems/BulletSystem.h"
#include "Systems/PlayerController.h"
#include "Logger.h"
#include "Screen.h"

#include <SFML/Graphics/Sprite.hpp>

class GameScreen final : public Screen
{
public:
    explicit GameScreen(SpaceInvaders& game);
    ~GameScreen() override = default;

    void Activate() override;
    void Shutdown() override;
    void HandleEvents(const std::optional<sf::Event>& event) override;

    void Update(const sf::Time& deltaTime) override;
    void Render() override;

private:
    Logger _logger;

    // Rendering layers
    std::unique_ptr<sf::RenderTexture> _backgroundLayer;
    std::unique_ptr<sf::RenderTexture> _gameLayer;
    std::unique_ptr<sf::RenderTexture> _uiLayer;

    // Resources


    // Systems
    PlayerController _playerController;
    BulletSystem _bulletSystem;

    // Utilities
    sf::Sprite CreateRenderSprite(const sf::RenderTexture& renderTexture);
};

#endif
