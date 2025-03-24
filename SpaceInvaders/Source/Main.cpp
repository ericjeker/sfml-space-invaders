// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Configuration.h"
#include "SpaceInvaders.h"

#include <SFML/Graphics.hpp>

/**
 * Scope is everything. The main function scope everything. We configure a container for our game, the Window.
 */
int main()
{
    // Getting the configuration, a simple struct
    Configuration configuration;

    // Initialize the window.
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(configuration.WindowSize), "SFML Project", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // Initialize the game client and running it
    SpaceInvaders spaceInvaders(window, configuration);
    spaceInvaders.Run();

    return 0;
}
