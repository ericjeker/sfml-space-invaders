// Copyright (c) Eric Jeker. All Rights Reserved.

#include <gtest/gtest.h>
#include <SFML/System/Vector2.hpp>
#include <optional>
#include <string>

// Note: This is a simple way to gain access to the functions in the anonymous namespace for testing.
// For larger projects, it might be preferable to move the functions to be tested into a header file
// to make them publicly accessible for testing.
#include "GameScreen/Systems/PlayerController.cpp"

// --- Tests for CheckOutOfBounds ---

TEST(PlayerControllerLogic, CheckOutOfBounds_StaysWithinBounds)
{
	const CheckOutOfBoundsIn params = {.position = {400.f, 500.f}, .screenBounds = {800, 600}};
	const auto [newPosition, error] = CheckOutOfBounds(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_EQ(newPosition.x, 400.f);
}

TEST(PlayerControllerLogic, CheckOutOfBounds_ClampedToLeft)
{
	// Position is too far left (10.f), should be clamped to the minimum boundary (50.f)
	const CheckOutOfBoundsIn params = {.position = {10.f, 500.f}, .screenBounds = {800, 600}};
	const auto [newPosition, error] = CheckOutOfBounds(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_EQ(newPosition.x, 50.f);
}

TEST(PlayerControllerLogic, CheckOutOfBounds_ClampedToRight)
{
	// Position is too far right (795.f), should be clamped to the maximum boundary (750.f)
	const CheckOutOfBoundsIn params = {.position = {795.f, 500.f}, .screenBounds = {800, 600}};
	const auto [newPosition, error] = CheckOutOfBounds(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_EQ(newPosition.x, 750.f);
}

// --- Tests for HandlePlayerMovement ---

TEST(PlayerControllerLogic, HandlePlayerMovement_MovesLeft)
{
	const PlayerMovementIn params = {.position = {400.f, 500.f}, .isMovingLeft = true, .isMovingRight = false};
	const auto [newPosition, error] = HandlePlayerMovement(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_EQ(newPosition.x, 380.f); // 400 - 20
	EXPECT_EQ(newPosition.y, 500.f);
}

TEST(PlayerControllerLogic, HandlePlayerMovement_MovesRight)
{
	const PlayerMovementIn params = {.position = {400.f, 500.f}, .isMovingLeft = false, .isMovingRight = true};
	const auto [newPosition, error] = HandlePlayerMovement(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_EQ(newPosition.x, 420.f); // 400 + 20
	EXPECT_EQ(newPosition.y, 500.f);
}

TEST(PlayerControllerLogic, HandlePlayerMovement_StandsStill)
{
	const PlayerMovementIn params = {.position = {400.f, 500.f}, .isMovingLeft = false, .isMovingRight = false};
	const auto [newPosition, error] = HandlePlayerMovement(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_EQ(newPosition.x, 400.f);
	EXPECT_EQ(newPosition.y, 500.f);
}

// --- Tests for HandleShootingAndCooldown ---

TEST(PlayerControllerLogic, HandleShooting_CanShootWhenReady)
{
	// Cooldown is negative, so player is ready to shoot.
	const ShootingAndCooldownIn params = {.currentCooldown = -0.1f, .cooldownDuration = 0.5f, .deltaTime = 0.016f, .isShooting = true};
	const auto [result, error] = HandleShootingAndCooldown(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_TRUE(result.shouldSpawnBullet);
	EXPECT_EQ(result.newCooldown, 0.5f); // Cooldown is reset
}

TEST(PlayerControllerLogic, HandleShooting_CannotShootWhenOnCooldown)
{
	// Cooldown is positive, player cannot shoot.
	const ShootingAndCooldownIn params = {.currentCooldown = 0.3f, .cooldownDuration = 0.5f, .deltaTime = 0.016f, .isShooting = true};
	const auto [result, error] = HandleShootingAndCooldown(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_FALSE(result.shouldSpawnBullet);
	EXPECT_NEAR(result.newCooldown, 0.3f - 0.016f, 0.0001f); // Cooldown is reduced
}

TEST(PlayerControllerLogic, HandleShooting_CooldownReducesOverTime)
{
	// Cooldown is positive and the player is not shooting.
	const ShootingAndCooldownIn params = {.currentCooldown = 0.3f, .cooldownDuration = 0.5f, .deltaTime = 0.016f, .isShooting = false};
	const auto [result, error] = HandleShootingAndCooldown(params);

	ASSERT_FALSE(error.has_value());
	EXPECT_FALSE(result.shouldSpawnBullet);
	EXPECT_NEAR(result.newCooldown, 0.3f - 0.016f, 0.0001f); // Cooldown is reduced
}