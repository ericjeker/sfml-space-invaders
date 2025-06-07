// Copyright (c) Eric Jeker. All Rights Reserved.

#include "SpaceInvaders.h"

#include "PauseScreen/PauseScreen.h"

#include <SFML/Graphics.hpp>

#include <GameScreen/GameScreen.h>
#include <TitleScreen/TitleScreen.h>

/**
 * Initialize the game. This is the place where we want to:
 *
 * - add all the game screens
 * - initialize the managers (sounds, particles, physics, network, settings, storage, inputs, resources)
 * - catch some global events (resize, focus, exit)
 */
SpaceInvaders::SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration)
	: Game(window, configuration)
	, _logger("SpaceInvaders", configuration.LogLevel)
{
	_logger.Debug("Game initialized");

	// TODO: Load saved settings

	// TODO: Load saved state

	// Initialize global resources
	const auto font = std::make_shared<sf::Font>("Assets/Fonts/Orbitron/static/Orbitron-Regular.ttf");
	GetResourceManager().SetResource<sf::Font>("DefaultFont", font);

	// TODO: Initialize physics world and add to game state

	// Initialize Game Screens (or scenes), all screens receive the game itself in parameter
	_screenManager.RegisterScreen(typeid(TitleScreen), [this]()
								  { return std::make_unique<TitleScreen>(*this); });
	_screenManager.RegisterScreen(typeid(GameScreen), [this]()
								  { return std::make_unique<GameScreen>(*this); });
	_screenManager.RegisterScreen(typeid(PauseScreen), [this]()
								  { return std::make_unique<PauseScreen>(*this); });

	// Set and Activate threene initial screen
	_screenManager.SetCurrentScreen(typeid(TitleScreen));
}

/**
 * Run the game, we start the Update loop.
 * This will keep running as long as the window is open.
 */
void SpaceInvaders::Run()
{
	_logger.Debug("Game started");

	sf::Clock clock;

	// Starting the game loop
	while (_window.isOpen())
	{
		// Global events, but local events are managed by screen
		while (const std::optional<sf::Event> event = _window.pollEvent())
		{
			HandleEvents(event);
		}

		// Execute all the scheduled commands we didn't immediately execute during HandleEvents
		ExecuteDeferredCommands();

		// TODO: https://medium.com/@tglaiel/how-to-make-your-game-run-at-60fps-24c61210fe75
		sf::Time deltaTime = clock.restart();
		Update(deltaTime);

		// And finally, we render the screen
		Render();
	}
}

void SpaceInvaders::Exit()
{
	_logger.Debug("Shutting down SpaceInvaders");

	// We shut down the screen to unload the resources
	_logger.Debug("Cleaning up ScreenManager");
	_screenManager.CleanUp();
	_logger.Debug("Cleaning up ResourceManager");
	_resourceManager.CleanUp();
	_logger.Debug("Closing the window");
	_window.close();
}

SpaceInvadersState& SpaceInvaders::GetState()
{
	return _state;
}

/**
 * Handles incoming events and performs appropriate actions based on the event type.
 * Delegates the event handling to the current screen and manages global events such as
 * window close, focus lost, and focus gained.
 *
 * @param event The optional event to be processed. If the event exists, its type is checked
 *              and corresponding actions are executed.
 */
void SpaceInvaders::HandleEvents(const std::optional<sf::Event>& event)
{
	// We first let the current screen handle the event
	_screenManager.HandleEvents(event);

	if (event->is<sf::Event::Closed>())
	{
		OnClose();
	}
	else if (event->is<sf::Event::FocusLost>())
	{
		OnFocusLost();
	}
	else if (event->is<sf::Event::FocusGained>())
	{
		OnFocusGained();
	}
}

void SpaceInvaders::OnFocusLost()
{
	_logger.Debug("Focus lost");
	_state.isPaused = true;
}

void SpaceInvaders::OnFocusGained()
{
	_logger.Debug("Focus gained");
	_state.isPaused = false;
}

void SpaceInvaders::OnResize()
{
	_logger.Debug("Window resized");
}

void SpaceInvaders::OnClose()
{
	_logger.Debug("Shutting down SpaceInvaders");
	Exit();
}

/**
 * Updates the state of the game by delegating the update logic
 * to the current screen being managed by the screen manager.
 *
 * @param deltaTime The amount of time elapsed since the last update call.
 */
void SpaceInvaders::Update(const sf::Time& deltaTime) const
{
	// Delegate the update to the current screen
	_screenManager.Update(deltaTime);
}

/**
 * Renders the current screen of the game. This method is responsible for:
 *
 * - Clearing the render window to prepare for a fresh frame.
 * - Delegating the rendering process to the screen manager, which manages the active screen.
 * - Displaying the rendered frame in the render window.
 */
void SpaceInvaders::Render() const
{
	_window.clear();
	_screenManager.Render();
	_window.display();
}
