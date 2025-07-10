// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Configuration.h"
#include "EngineContext.h"
#include "SpaceInvaders.h"

#include <SFML/Graphics.hpp>

/**
 * Scope is everything. The main function scopes everything. We configure a container for our game, the Window. The
 * game itself will take care of the game loop.
 */
int main()
{
	// Create the window mode
	const sf::VideoMode mode(Configuration::WindowSize);

	// Enable anti-aliasing
	sf::ContextSettings settings;
	settings.antiAliasingLevel = Configuration::AntiAliasingLevel;

	// Initialize the window, make it beautiful
	auto window = std::make_unique<sf::RenderWindow>(
		sf::RenderWindow(mode, "Space Invaders", Configuration::WindowStyle, Configuration::WindowState, settings));
	window->setFramerateLimit(Configuration::FramesPerSecond);
	window->setVerticalSyncEnabled(Configuration::IsVSync);

	// Create the engine context
	auto engineContext = std::make_unique<EngineContext>();
	engineContext->SetFileManager(std::make_unique<FileManager>());
	engineContext->SetResourceManager(std::make_unique<ResourceManager>());
	engineContext->SetScreenManager(std::make_unique<ScreenManager>());
	engineContext->SetWindow(std::move(window));

	// Initialize the game client and running it, which basically start the program. That's why we are all here today.
	SpaceInvaders spaceInvaders(std::move(engineContext));
	spaceInvaders.Run();

	return 0;
}
