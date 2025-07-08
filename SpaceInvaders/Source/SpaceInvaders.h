// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "EngineContext.h"
#include "GameInstance.h"
#include "SpaceInvadersState.h"

#include "Managers/ResourceManager.h"
#include "Managers/ScreenManager.h"

#include <SFML/Graphics.hpp>


class SpaceInvaders final : public GameInstance
{
public:
	explicit SpaceInvaders(std::unique_ptr<EngineContext> engineContext);

	// Called for starting the game after it's configured and initialized
	void Run() override;
	// Exit the game and clean up the resources
	void Exit() override;

	SpaceInvadersState& GetState();

private:
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
