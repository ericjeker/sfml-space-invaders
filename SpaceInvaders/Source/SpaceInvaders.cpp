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
SpaceInvaders::SpaceInvaders(std::unique_ptr<EngineContext> engineContext)
	: GameInstance(std::move(engineContext))
	, _logger("SpaceInvaders", GetEngineContext().GetConfiguration().LogLevel)
{
	_logger.Debug("Game initialized");

	// TODO: Load saved settings

	// TODO: Load saved state

	// Initialize global resources
	auto& resourceManager = GetEngineContext().GetResourceManager();
	resourceManager.LoadResourcesFromManifest("Assets/manifest.json");

	// TODO: Initialize physics world and add to game state

	auto& screenManager = GetEngineContext().GetScreenManager();
	// Initialize Game Screens (or scenes), all screens receive the game itself in parameter
	screenManager.RegisterScreen(typeid(TitleScreen), [this]()
								  { return std::make_unique<TitleScreen>(*this); });
	screenManager.RegisterScreen(typeid(GameScreen), [this]()
								  { return std::make_unique<GameScreen>(*this); });
	screenManager.RegisterScreen(typeid(PauseScreen), [this]()
								  { return std::make_unique<PauseScreen>(*this); });

	// Set and Activate the initial screen
	screenManager.SetCurrentScreen(typeid(TitleScreen));
}

/**
 * Run the game, we start the Update loop.
 * This will keep running as long as the window is open.
 */
void SpaceInvaders::Run()
{
	_logger.Debug("Game started");

	sf::Clock clock;

	auto& window = GetEngineContext().GetWindow();

	// Starting the game loop
	while (window.isOpen())
	{
		// Global events (window), but local events are managed by screen
		while (const std::optional<sf::Event> event = window.pollEvent())
		{
			HandleEvents(event);
		}

		// Execute all the scheduled commands we didn't immediately execute during HandleEvents
		ExecuteDeferredCommands();

		// TODO: Explore this article as a way to improve the time management system:
		//   https://medium.com/@tglaiel/how-to-make-your-game-run-at-60fps-24c61210fe75
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
	GetEngineContext().GetScreenManager().CleanUp();
	_logger.Debug("Cleaning up ResourceManager");
	GetEngineContext().GetResourceManager().CleanUp();
	_logger.Debug("Closing the window");
	GetEngineContext().GetWindow().close();
}

SpaceInvadersState& SpaceInvaders::GetState()
{
	return _state;
}

void SpaceInvaders::HandleEvents(const std::optional<sf::Event>& event)
{
	// We first let the current screen handle the event
	GetEngineContext().GetScreenManager().HandleEvents(event);

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

void SpaceInvaders::OnResize() const
{
	_logger.Debug("Window resized");
}

void SpaceInvaders::OnClose()
{
	_logger.Debug("Shutting down SpaceInvaders");
	Exit();
}

void SpaceInvaders::Update(const sf::Time& deltaTime) const
{
	// Delegate the update to the screen manager
	GetEngineContext().GetScreenManager().Update(deltaTime);
}

void SpaceInvaders::Render() const
{
	GetEngineContext().GetWindow().clear();
	// Delegate the rendering to the screen manager
	GetEngineContext().GetScreenManager().Render();
	GetEngineContext().GetWindow().display();
}
