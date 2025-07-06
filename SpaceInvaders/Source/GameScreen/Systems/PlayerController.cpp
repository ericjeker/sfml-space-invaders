// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "GameScreen/Systems/PlayerController.h"

#include "GameScreen/Entities/PlayerState.h"
#include "GameScreen/Systems/BulletSystem.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

/**
 * By keeping the private functions here, in an anonymouse namespace, we encapsulate
 * the internal processing to this translation unit.
 *
 * The PlayerController.h file still contains the public interface.
 */
namespace
{

void CheckOutOfBounds(const PlayerController::UpdateContext& context, PlayerState& player)
{
	if (player.position.x < 100.f / 2)
	{
		player.position.x = 100.f / 2;
	}
	else if (player.position.x > context.screenBounds.x - 100.f / 2)
	{
		player.position.x = context.screenBounds.x - 100.f / 2;
	}
}

void HandlePlayerMovement(PlayerState& player)
{
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
}

void HandleShootingAndCooldown(const PlayerController::UpdateContext& context, PlayerState& player,
							   BulletCollection& bullets)
{
	if (player.cooldown < 0.f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			player.cooldown = player.cooldownDuration;
			BulletSystem::SpawnBullet(bullets, player.position);
		}
	}
	else
	{
		player.cooldown -= context.deltaTime.asSeconds();
	}
}

} // namespace


/**
 * PlayerController
 */
void PlayerController::Initialize(PlayerState& player, const sf::Vector2f position)
{
	// Initialize the player's position and velocity
	player.position = position;
	player.velocity = sf::Vector2f(0.f, 0.f);
	player.health = 100;
	player.cooldown = 0.f;
}

void PlayerController::Update(const UpdateContext& context, PlayerState& player, BulletCollection& bullets)
{
	HandleShootingAndCooldown(context, player, bullets);
	HandlePlayerMovement(player);
	CheckOutOfBounds(context, player);
}

void PlayerController::Render(sf::RenderTexture& renderTexture, const PlayerState& playerState,
							  sf::RectangleShape& rectangle)
{
	rectangle.setPosition(playerState.position);
	rectangle.setOrigin(rectangle.getSize() / 2.f);
	renderTexture.draw(rectangle);
}
