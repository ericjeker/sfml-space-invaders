// Copyright (c) Eric Jeker. All Rights Reserved.

#include "TitleScreen.h"

#include <GameScreen.h>
#include <SpaceInvaders.h>

TitleScreen::TitleScreen(SpaceInvaders& game) : Screen(game), _logger("TitleScreen", game.GetConfiguration().LogLevel)
{
}

void TitleScreen::Activate()
{
    _logger.Debug("Activating TitleScreen");

    // Create a window instance from the game to fetch size
    auto& window = GetGame().GetWindow();
    const float centerX = window.getSize().x / 2.f;
    const float centerY = window.getSize().y / 2.f;

    std::shared_ptr<sf::Font> font = GetGame().GetResourceManager().GetResource<sf::Font>("Global::Font");

    // Create title text
    auto title = std::make_shared<sf::Text>(*font);
    title->setString("Space Invaders");
    title->setCharacterSize(50);
    title->setFillColor(sf::Color::White);
    title->setStyle(sf::Text::Bold);
    title->setOrigin(title->getGlobalBounds().getCenter());
    title->setPosition({centerX, centerY - 250.f});

    // Create Play button
    auto playButton = std::make_shared<sf::Text>(*font);
    playButton->setString("Play");
    playButton->setCharacterSize(40);
    playButton->setFillColor(sf::Color::White);
    playButton->setOrigin(playButton->getGlobalBounds().getCenter());
    playButton->setPosition({centerX, centerY});

    // Create Exit button
    auto exitButton = std::make_shared<sf::Text>(*font);
    exitButton->setString("Exit");
    exitButton->setCharacterSize(30);
    exitButton->setFillColor(sf::Color::White);
    exitButton->setOrigin(exitButton->getGlobalBounds().getCenter());
    exitButton->setPosition({centerX, centerY + 100.f});

    ResourceManager& resourceManager = GetGame().GetResourceManager();
    resourceManager.SetResource("TitleScreen::Title", std::shared_ptr<sf::Text>(title));
    resourceManager.SetResource("TitleScreen::PlayButton", std::shared_ptr<sf::Text>(playButton));
    resourceManager.SetResource("TitleScreen::ExitButton", std::shared_ptr<sf::Text>(exitButton));
}

void TitleScreen::Update(const TimeTicker& timeTicker) {}

void TitleScreen::Render() const
{
    sf::RenderWindow& window = GetGame().GetWindow();
    ResourceManager& resourceManager = GetGame().GetResourceManager();
    window.draw(*resourceManager.GetResource<sf::Text>("TitleScreen::Title"));
    window.draw(*resourceManager.GetResource<sf::Text>("TitleScreen::PlayButton"));
    window.draw(*resourceManager.GetResource<sf::Text>("TitleScreen::ExitButton"));
}

void TitleScreen::Shutdown()
{
    _logger.Debug("Shutting down TitleScreen");
    ResourceManager& resourceManager = GetGame().GetResourceManager();
    resourceManager.UnloadResource("TitleScreen::Title");
    resourceManager.UnloadResource("TitleScreen::PlayButton");
    resourceManager.UnloadResource("TitleScreen::ExitButton");
}

void TitleScreen::HandleEvents(const std::optional<sf::Event>& event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        OnKeyPressed(*keyPressed);
    }
    else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
    {
        OnMouseMove(*mouseMoved);
    }
    else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
    {
        OnMousePressed(*mousePressed);
    }
}

void TitleScreen::OnKeyPressed(const sf::Event::KeyPressed& keyPressed) const
{
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
    {
        GetGame().Exit();
    }
}

void TitleScreen::OnMouseMove(const sf::Event::MouseMoved& event) const
{
    if (event.position.x && event.position.y)
    {
        GetGame().GetState().mousePos.x = event.position.x;
        GetGame().GetState().mousePos.y = event.position.y;
    }
}

void TitleScreen::OnMousePressed(const sf::Event::MouseButtonPressed& event) const
{
    _logger.Debug(std::format("OnMousePressed at ({}, {})", event.position.x, event.position.y));

    auto mousePos = event.position;
    auto exitButton = GetGame().GetResourceManager().GetResource<sf::Text>("TitleScreen::ExitButton");
    if (exitButton->getGlobalBounds().contains(sf::Vector2<float>(mousePos)))
    {
        GetGame().Exit();
    }

    auto playButton = GetGame().GetResourceManager().GetResource<sf::Text>("TitleScreen::PlayButton");
    if (playButton->getGlobalBounds().contains(sf::Vector2<float>(mousePos)))
    {
        GetGame().GetScreenManager().SetCurrentScreen<GameScreen>();
    }
}
