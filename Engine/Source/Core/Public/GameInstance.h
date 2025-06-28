// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef GAME_H
#define GAME_H

#include "Configuration.h"
#include "EngineContext.h"

#include "Managers/ResourceManager.h"
#include "Managers/ScreenManager.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <queue>

class GameInstance
{
public:
    explicit GameInstance(std::unique_ptr<EngineContext> engineContext);
    virtual ~GameInstance() = default;

    // Called for starting the game after it's configured and initialized
    virtual void Run() = 0;
    // Exit the game and clean up the resources
    virtual void Exit() = 0;

	[[nodiscard]] EngineContext& GetEngineContext() const;

	/**
	 * Updates the state of the game by delegating the update logic
	 * to the current screen being managed by the screen manager.
	 *
	 * @param deltaTime The amount of time elapsed since the last update call.
	 */
	virtual void Update(const sf::Time& deltaTime) const = 0;

	/**
	 * Renders the current screen of the game. This method is responsible for:
	 *
	 * - Clearing the render window to prepare for a fresh frame.
	 * - Delegating the rendering process to the screen manager, which manages the active screen.
	 * - Displaying the rendered frame in the render window.
	 */
	virtual void Render() const = 0;

	/**
	 * Handles incoming events and performs appropriate actions based on the event type.
	 * Delegates the event handling to the current screen and manages global events such as
	 * window close, focus lost, and focus gained.
	 *
	 * @param event The optional event to be processed. If the event exists, its type is checked
	 *              and corresponding actions are executed.
	 */
	virtual void HandleEvents(const std::optional<sf::Event>& event) = 0;

	/**
	 * Schedules a command to be executed later. The given command is added
	 * to an internal queue and will not execute immediately.
	 *
	 * This method is typically used to defer certain actions or game state
	 * changes until the main game loop processes them, ensuring that
	 * commands are executed in a sequential and managed manner.
	 *
	 * TODO: Command Management should be in a CommandManager or EventManager
	 *
	 * @param command A `std::function<void()>` representing the task or
	 * action to be scheduled for deferred execution.
	 */
	void ScheduleCommand(const std::function<void()>& command);
    void ExecuteDeferredCommands();

protected:
	std::unique_ptr<EngineContext> _engineContext;

	// The deferred commands queue
    std::queue<std::function<void()>> _deferredCommands;
};

#endif
