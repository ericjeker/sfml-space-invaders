// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Configuration.h"
#include "SpaceInvaders.h"

#include <SFML/Graphics.hpp>

/**
 * Scope is everything. The main function scopes everything. We configure a container for our game, the Window. The
 * game itself will take care of the game loop.
 */
int main()
{
    // Getting the global configuration of the program, a simple struct
    constexpr Configuration configuration;

	// Create the window mode
	const sf::VideoMode mode(configuration.WindowSize);

	// Enable anti-aliasing
	sf::ContextSettings settings;
	settings.antiAliasingLevel = configuration.AntiAliasingLevel;

	// Initialize the window, make it beautiful
    auto window = sf::RenderWindow(mode, "Space Invaders", sf::Style::Close, sf::State::Windowed, settings);
    window.setFramerateLimit(configuration.FramesPerSecond);
    window.setVerticalSyncEnabled(configuration.IsVSync);

    // Initialize the game client and running it, which basically start the program. That's why we are all here today.
    SpaceInvaders spaceInvaders(window, configuration);
    spaceInvaders.Run();

    return 0;
}
