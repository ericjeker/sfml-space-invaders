// Copyright (c) Eric Jeker. All Rights Reserved.

#include "TitleScreen.h"

#include <SpaceInvaders.h>

TitleScreen::TitleScreen(SpaceInvaders& game) : Screen(game), _logger("TitleScreen", game.GetConfiguration().LogLevel)
{
}

void TitleScreen::Activate()
{
    _logger.Debug("Activating TitleScreen");

    // Create a window instance from the game to fetch size
    auto& window = GetGame().GetWindow();

    sf::Font font;
    // The Assets folder is relative to the current working directory
    if (!font.openFromFile("Assets/Fonts/Orbitron/static/Orbitron-Regular.ttf"))
    {
        _logger.Error("Failed to load font!");
        return;
    }

    const float centerX = window.getSize().x / 2.f;
    const float centerY = window.getSize().y / 2.f;

    // Create title text
    sf::Text* title = new sf::Text(font);
    title->setString("Space Invaders");
    title->setCharacterSize(50);
    title->setFillColor(sf::Color::White);
    title->setStyle(sf::Text::Bold);
    title->setOrigin({0.5f, 0.5f});
    title->setPosition({centerX, 50.f});

    // Create Play button
    sf::Text* playButton = new sf::Text(font);
    playButton->setString("Play");
    playButton->setCharacterSize(40);
    playButton->setFillColor(sf::Color::White);
    playButton->setOrigin({0.5f, 0.5f});
    playButton->setPosition({centerX, centerY});

    // Create Exit button
    sf::Text* exitButton = new sf::Text(font);
    exitButton->setFont(font);
    exitButton->setString("Exit");
    exitButton->setCharacterSize(30);
    exitButton->setFillColor(sf::Color::White);
    exitButton->setOrigin({0.5f, 0.5f});
    exitButton->setPosition({centerX, centerY + 100.f});

    ResourceManager& resourceManager = GetGame().GetResourceManager();
    resourceManager.SetResource("title", title);
    resourceManager.SetResource("playButton", playButton);
    resourceManager.SetResource("exitButton", exitButton);
}

void TitleScreen::Update(const TimeTicker& timeTicker) {}

void TitleScreen::Render() const
{
    _logger.Debug("Rendering TitleScreen");

    sf::RenderWindow& window = GetGame().GetWindow();
    ResourceManager& resourceManager = GetGame().GetResourceManager();
    window.draw(resourceManager.GetResource<sf::Text>("title"));
    window.draw(resourceManager.GetResource<sf::Text>("playButton"));
    window.draw(resourceManager.GetResource<sf::Text>("exitButton"));
}

void TitleScreen::Shutdown()
{
    _logger.Debug("Shutting down TitleScreen");
    ResourceManager& resourceManager = GetGame().GetResourceManager();
    resourceManager.UnloadResource("title");
    resourceManager.UnloadResource("playButton");
    resourceManager.UnloadResource("exitButton");
}


// sf::Event event;
// while (window.waitEvent(event))
// {
//     if (event.type == sf::Event::Closed)
//     {
//         GetGame().Exit(); // Calls the game exit logic
//         break;
//     }
//
//     if (event.type == sf::Event::MouseButtonPressed)
//     {
//         sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
//
//         if (playButton.getGlobalBounds().contains(mousePos))
//         {
//             GetGame().GetScreenManager().SetCurrentScreen(GameScreen);
//             break;
//         }
//         else if (exitButton.getGlobalBounds().contains(mousePos))
//         {
//             GetGame().Exit();
//             break;
//         }
//     }
// }
