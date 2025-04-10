// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <Configuration.h>
#include <GameState.h>


#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>


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
};


#endif
