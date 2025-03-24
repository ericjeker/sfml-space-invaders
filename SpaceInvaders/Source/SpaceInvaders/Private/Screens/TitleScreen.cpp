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

    /** Load resources when the Screen is activated */
    const auto circle = new sf::CircleShape(100.f);
    circle->setFillColor(sf::Color::Red);
    circle->setOutlineColor(sf::Color::Blue);
    circle->setOutlineThickness(5.f);
    circle->setOrigin({circle->getRadius(), circle->getRadius()});
    circle->setPosition({centerX, centerY});
    GetGame().GetResourceManager().SetResource<sf::CircleShape>("circle", circle);

    // TODO: These text are making everything crash and burn
    // Create title text
    // sf::Text* title = new sf::Text(font);
    // title->setString("Space Invaders");
    // title->setCharacterSize(50);
    // title->setFillColor(sf::Color::White);
    // title->setStyle(sf::Text::Bold);
    // title->setOrigin({0.5f, 0.5f});
    // title->setPosition({centerX, 50.f});
    //
    // // Create Play button
    // sf::Text* playButton = new sf::Text(font);
    // playButton->setString("Play");
    // playButton->setCharacterSize(40);
    // playButton->setFillColor(sf::Color::White);
    // playButton->setOrigin({0.5f, 0.5f});
    // playButton->setPosition({centerX, centerY});
    //
    // // Create Exit button
    // sf::Text* exitButton = new sf::Text(font);
    // exitButton->setFont(font);
    // exitButton->setString("Exit");
    // exitButton->setCharacterSize(30);
    // exitButton->setFillColor(sf::Color::White);
    // exitButton->setOrigin({0.5f, 0.5f});
    // exitButton->setPosition({centerX, centerY + 100.f});
    //
    // ResourceManager& resourceManager = GetGame().GetResourceManager();
    // resourceManager.SetResource("title", title);
    // resourceManager.SetResource("playButton", playButton);
    // resourceManager.SetResource("exitButton", exitButton);
}

void TitleScreen::Update(const TimeTicker& timeTicker) {}

void TitleScreen::Render() const
{
    sf::RenderWindow& window = GetGame().GetWindow();
    ResourceManager& resourceManager = GetGame().GetResourceManager();
    window.draw(resourceManager.GetResource<sf::CircleShape>("circle"));
    // window.draw(resourceManager.GetResource<sf::Text>("title"));
    // window.draw(resourceManager.GetResource<sf::Text>("playButton"));
    // window.draw(resourceManager.GetResource<sf::Text>("exitButton"));
}

void TitleScreen::Shutdown()
{
    _logger.Debug("Shutting down TitleScreen");
    ResourceManager& resourceManager = GetGame().GetResourceManager();
    resourceManager.UnloadResource("circle");
    // resourceManager.UnloadResource("title");
    // resourceManager.UnloadResource("playButton");
    // resourceManager.UnloadResource("exitButton");
}

void TitleScreen::HandleEvents()
{
    GetGame().GetWindow().handleEvents([this](const sf::Event::Closed& event) { this->OnClose(event); },
                                       [this](const sf::Event::KeyPressed& event) { this->OnKeyPressed(event); });
}

void TitleScreen::OnClose(const sf::Event::Closed&)
{
    // We shut down the screen to unload the resources
    GetGame().Exit();
}

void TitleScreen::OnKeyPressed(const sf::Event::KeyPressed& keyPressed) const
{
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
    {
        GetGame().Exit();
    }
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
