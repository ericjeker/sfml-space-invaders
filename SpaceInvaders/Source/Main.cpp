// Copyright (c) Eric Jeker. All Rights Reserved.

#include <SFML/Graphics.hpp>
#include "Core/Public/Configuration.h"
#include "SpaceInvaders/Public/SpaceInvaders.h"

int main()
{
    Configuration configuration;
    auto window = sf::RenderWindow(sf::VideoMode(configuration.WindowSize), "SFML Project");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

	SpaceInvaders spaceInvaders(window, configuration);
    spaceInvaders.Run();

    return 0;
}
