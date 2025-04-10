// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Systems/PlayerController.h"

#include <SFML/Graphics/RectangleShape.hpp>

PlayerController::PlayerController(const sf::RenderWindow& window, const Configuration& configuration)
    : _logger("PlayerController", configuration.LogLevel), _window(window), _configuration(configuration)
{
}

void PlayerController::Initialize(Player& player)
{
    player.position = sf::Vector2f(_window.getSize().x / 2.f, _window.getSize().y - 200.f);
    player.velocity = sf::Vector2f(0.f, 0.f);
    player.health = 100;
}

void PlayerController::Update(const sf::Time& deltaTime, Player& player)
{
    // Apply input to the player's velocity

    // Update the player's position based on the velocity
    player.position += player.velocity * deltaTime.asSeconds();
}

void PlayerController::Render(sf::RenderTexture& renderTexture, Player& player) const
{
    sf::RectangleShape rectangleShape(sf::Vector2f(100.f, 40.f));
    rectangleShape.setFillColor(sf::Color::White);
    rectangleShape.setPosition(player.position);
    rectangleShape.setOrigin(rectangleShape.getSize() / 2.f);
    renderTexture.draw(rectangleShape);
}
