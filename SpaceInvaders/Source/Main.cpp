// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Configuration.h"
#include "SpaceInvaders.h"

#include <SFML/Graphics.hpp>

int main()
{
    Configuration configuration;

    /** Initialize the window. */
    auto window = sf::RenderWindow(sf::VideoMode(configuration.WindowSize), "SFML Project", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    /** Initialize the game. */
    SpaceInvaders spaceInvaders(window, configuration);
    spaceInvaders.Run();

    return 0;
}
