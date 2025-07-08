// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "PlayerController.h"

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

struct CheckOutOfBoundsIn
{
	sf::Vector2f position;
	sf::Vector2u screenBounds;
};

std::pair<sf::Vector2f, std::optional<std::string>> CheckOutOfBounds(const CheckOutOfBoundsIn& params)
{
	sf::Vector2f newPosition = params.position;
	if (newPosition.x < 100.f / 2)
	{
		newPosition.x = 100.f / 2;
	}
	else if (newPosition.x > static_cast<float>(params.screenBounds.x) - 100.f / 2)
	{
		newPosition.x = static_cast<float>(params.screenBounds.x) - 100.f / 2;
	}

	return {newPosition, std::nullopt};
}

struct PlayerMovementIn
{
	sf::Vector2f position;
	bool isMovingLeft{false};
	bool isMovingRight{false};
};

std::pair<sf::Vector2f, std::optional<std::string>> HandlePlayerMovement(const PlayerMovementIn& params)
{
	sf::Vector2f newPosition = params.position;
	// TODO: This should be handled with the CommandRegistry
	if (params.isMovingLeft)
	{
		newPosition.x -= 20.f;
	}
	else if (params.isMovingRight)
	{
		newPosition.x += 20.f;
	}

	// Update the player's position based on the velocity
	// player.position += player.velocity * delta;
	return {newPosition, std::nullopt};
}

struct ShootingAndCooldownIn
{
	float currentCooldown;
	float cooldownDuration;
	float deltaTime;
	bool isShooting;
};

struct ShootingAndCooldownOut
{
	float newCooldown;
	bool shouldSpawnBullet;
};

std::pair<ShootingAndCooldownOut, std::optional<std::string>>
HandleShootingAndCooldown(const ShootingAndCooldownIn& params)
{
	ShootingAndCooldownOut result = {params.currentCooldown, false};

	if (result.newCooldown < 0.f)
	{
		// TODO: This should be handled with the CommandRegistry
		if (params.isShooting)
		{
			result.newCooldown = params.cooldownDuration;
			result.shouldSpawnBullet = true;
		}
	}
	else
	{
		result.newCooldown -= params.deltaTime;
	}

	return {result, std::nullopt};
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
	// Handle Shooting
	const ShootingAndCooldownIn shootingParams = {.currentCooldown = player.cooldown,
												  .cooldownDuration = player.cooldownDuration,
												  .deltaTime = context.deltaTime.asSeconds(),
												  .isShooting = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)};
	const auto [shootingResult, shootingError] = HandleShootingAndCooldown(shootingParams);
	if (!shootingError)
	{
		player.cooldown = shootingResult.newCooldown;
		if (shootingResult.shouldSpawnBullet)
		{
			BulletSystem::SpawnBullet(bullets, player.position);
		}
	}

	// Handle Movement
	const PlayerMovementIn movementParams = {.position = player.position,
											 .isMovingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A),
											 .isMovingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)};
	if (const auto [newPosition, moveError] = HandlePlayerMovement(movementParams); !moveError)
	{
		player.position = newPosition;
	}

	// Check Boundaries
	const CheckOutOfBoundsIn boundsParams = {.position = player.position, .screenBounds = context.screenBounds};
	if (const auto [boundedPosition, boundsError] = CheckOutOfBounds(boundsParams); !boundsError)
	{
		player.position = boundedPosition;
	}
}

void PlayerController::Render(sf::RenderTexture& renderTexture, const PlayerState& playerState,
							  sf::RectangleShape& rectangle)
{
	rectangle.setPosition(playerState.position);
	rectangle.setOrigin(rectangle.getSize() / 2.f);
	renderTexture.draw(rectangle);
}
