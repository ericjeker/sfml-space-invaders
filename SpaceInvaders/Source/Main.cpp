// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Configuration.h"
#include "SpaceInvaders.h"
// #include "FileManager.h"
// #include "ResourceManager.h"
// #include "SoundManager.h"
// #include "EventSystem.h"
#include "EngineContext.h"

#include <SFML/Graphics.hpp>
/**
 * Scope is everything. The main function scopes everything. We configure a container for our game, the Window. The
 * game itself will take care of the game loop.
 */
int main()
{
	// Create the engine context
	Configuration configuration;

	// Create the window mode
	const sf::VideoMode mode(configuration.WindowSize);

	// Enable anti-aliasing
	sf::ContextSettings settings;
	settings.antiAliasingLevel = configuration.AntiAliasingLevel;

	// Initialize the window, make it beautiful
	auto window = std::make_unique<sf::RenderWindow>(
		sf::RenderWindow(mode, "Space Invaders", sf::Style::None, sf::State::Fullscreen, settings));
	window->setFramerateLimit(configuration.FramesPerSecond);
	window->setVerticalSyncEnabled(configuration.IsVSync);

	// Create the engine context
	auto engineContext = std::make_unique<EngineContext>(configuration);
	engineContext->SetConfiguration(std::make_unique<Configuration>());
	engineContext->SetFileManager(std::make_unique<FileManager>());
	engineContext->SetResourceManager(
		std::make_unique<ResourceManager>(engineContext->GetFileManager(), engineContext->GetConfiguration()));
	engineContext->SetScreenManager(std::make_unique<ScreenManager>(engineContext->GetConfiguration()));
	engineContext->SetWindow(std::move(window));

	// Initialize the game client and running it, which basically start the program. That's why we are all here today.
	SpaceInvaders spaceInvaders(std::move(engineContext));
	spaceInvaders.Run();

	return 0;
}
