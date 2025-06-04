// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Configuration.h"
#include "GameScreen/Entities/Player.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

/**
 * @class PlayerController
 * @brief Handles the player's input, updates their state, and renders them on the screen.
 *
 * The PlayerController class is responsible for managing the player's behavior,
 * including initialization, updating based on input and physics, and rendering the
 * player to the appropriate render texture.
 *
 * The class is an orchestrator, it shouldn't hold any state and behavior but rather
 * delegate to components.
 */
class PlayerController
{
public:
    PlayerController(const sf::RenderWindow& window, const Configuration& configuration);
    ~PlayerController() = default;

    void Initialize(Player& player);
    void Update(const sf::Time& deltaTime, Player& player);
    void Render(sf::RenderTexture& renderTexture, Player& player) const;

private:
    Logger _logger;

    const sf::RenderWindow& _window;
    const Configuration& _configuration;

    std::unique_ptr<sf::RectangleShape> _rectangle;
};


#endif
