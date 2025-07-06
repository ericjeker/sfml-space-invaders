// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <SFML/System/Vector2.hpp>

// Forward declarations
namespace sf
{

class Time;
class RenderTexture;
class RectangleShape;

} // namespace sf

struct BulletCollection;
struct PlayerState;

/**
 * @namespace PlayerController
 * @brief Handles the player's input, updates their state, and renders them on the screen.
 *
 * The PlayerController class is responsible for managing the player's behavior,
 * including initialization, updating based on input and physics, and rendering the
 * player to the appropriate render texture.
 */
namespace PlayerController
{

void Initialize(PlayerState& player, sf::Vector2f position);

struct UpdateContext
{
	const sf::Time& deltaTime;
	sf::Vector2u screenBounds;
};

void Update(const UpdateContext& context, PlayerState& player, BulletCollection& bullets);
void Render(sf::RenderTexture& renderTexture, const PlayerState& playerState, sf::RectangleShape& rectangle);

}; // namespace PlayerController


#endif
