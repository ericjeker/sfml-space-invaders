// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "GameScreen/Systems/PlayerController.h"

PlayerController::PlayerController(const sf::RenderWindow& window, const Configuration& configuration)
	: _logger("PlayerController", configuration.LogLevel)
	, _window(window)
	, _configuration(configuration)
{
}

void PlayerController::Initialize(Player& player)
{
	// Initialize the player's position and velocity
	player.position = sf::Vector2f(_window.getSize().x / 2.f, _window.getSize().y - 200.f);
	player.velocity = sf::Vector2f(0.f, 0.f);
	player.health = 100;

	// Create the player resources
	_rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(100.f, 40.f));
	_rectangle->setFillColor(sf::Color::White);
}

void PlayerController::Update(const sf::Time& deltaTime, Player& player)
{
	/**
	 * The reason we don't do that in an HandleEvents() function is because HandleEvents is a polling system which
	 * means the events are only triggered once per "click" when here we can actually update the position at every
	 * frame.
	 */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		player.position.x += -20.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		player.position.x += 20.f;
	}

	// Update the player's position based on the velocity
	// player.position += player.velocity * delta;

	// Check if the paddle is out of the screen
	if (player.position.x < 100.f / 2)
	{
		player.position.x = 100.f / 2;
	}
	else if (player.position.x > _window.getSize().x - 100.f / 2)
	{
		player.position.x = _window.getSize().x - 100.f / 2;
	}
}

void PlayerController::Render(sf::RenderTexture& renderTexture, Player& player) const
{
	_rectangle->setPosition(player.position);
	_rectangle->setOrigin(_rectangle->getSize() / 2.f);
	renderTexture.draw(*_rectangle);
}
