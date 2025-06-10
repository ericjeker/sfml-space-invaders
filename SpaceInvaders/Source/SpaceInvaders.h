// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "Game.h"
#include "ResourceManager.h"
#include "ScreenManager.h"
#include "SpaceInvadersState.h"

#include <SFML/Graphics.hpp>


class SpaceInvaders final : public Game
{
public:
	SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration);

	// Called for starting the game after it's configured and initialized
	void Run() override;
	// Exit the game and clean up the resources
	void Exit() override;

	SpaceInvadersState& GetState();

private:
	const Logger _logger;
	SpaceInvadersState _state;

	// Events handling first
	void HandleEvents(const std::optional<sf::Event>& event) override;

	void Update(const sf::Time& deltaTime) const override;
	void Render() const override;

	// Game Events related to the Window
	void OnClose();
	void OnFocusLost();
	void OnFocusGained();
	void OnResize() const;
};

#endif
