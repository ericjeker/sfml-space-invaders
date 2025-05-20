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

    // Initialize the window, make it beautiful
    auto window = sf::RenderWindow(sf::VideoMode(configuration.WindowSize), "Space Invaders", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // Initialize the game client and running it, which basically start the program. That's why we are all here today.
    SpaceInvaders spaceInvaders(window, configuration);
    spaceInvaders.Run();

    return 0;
}
