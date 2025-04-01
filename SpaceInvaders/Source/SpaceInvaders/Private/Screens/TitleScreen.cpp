// Copyright (c) Eric Jeker. All Rights Reserved.

#include "TitleScreen.h"
#include "Ball.h"

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
    auto& resourceManager = GetGame().GetResourceManager();

    const float centerX = window.getSize().x / 2.f;
    const float centerY = window.getSize().y / 2.f;

    // Get the font from the global resources
    std::shared_ptr<sf::Font> font = resourceManager.GetResource<sf::Font>("Global::Font");

    // Create the render layers, everything will be rendered on these layers
    auto backgroundLayer = std::make_shared<sf::RenderTexture>(window.getSize());
    auto uiLayer = std::make_shared<sf::RenderTexture>(window.getSize());

    resourceManager.SetResource("TitleScreen::BackgroundLayer", backgroundLayer);
    resourceManager.SetResource("TitleScreen::UILayer", uiLayer);

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

    resourceManager.SetResource("TitleScreen::Title", title);
    resourceManager.SetResource("TitleScreen::PlayButton", playButton);
    resourceManager.SetResource("TitleScreen::ExitButton", exitButton);
}

void TitleScreen::Update(const TimeTicker& timeTicker) {}

void TitleScreen::Render() const
{
    sf::RenderWindow& window = GetGame().GetWindow();
    ResourceManager& resourceManager = GetGame().GetResourceManager();

    if (auto backgroundLayer = resourceManager.GetResource<sf::RenderTexture>("TitleScreen::BackgroundLayer"))
    {
        backgroundLayer->clear();

        // Draw the background layer to the window
        sf::Sprite backgroundSprite(backgroundLayer->getTexture());

        // Not very clear to me why the texture coordinates are flipped on the Y axis?
        backgroundSprite.setScale({1.f, -1.f});
        backgroundSprite.setPosition({0.f, static_cast<float>(backgroundLayer->getSize().y)});

        window.draw(backgroundSprite);
    }

    if (auto uiLayer = resourceManager.GetResource<sf::RenderTexture>("TitleScreen::UILayer"))
    {
        uiLayer->clear();

        uiLayer->draw(*resourceManager.GetResource<sf::Text>("TitleScreen::Title"));
        uiLayer->draw(*resourceManager.GetResource<sf::Text>("TitleScreen::PlayButton"));
        uiLayer->draw(*resourceManager.GetResource<sf::Text>("TitleScreen::ExitButton"));

        // Draw the UI layer to the window
        sf::Sprite uiSprite(uiLayer->getTexture());

        // Not very clear to me why the texture coordinates are flipped on the Y axis?
        uiSprite.setScale({1.f, -1.f});
        uiSprite.setPosition({0.f, static_cast<float>(uiLayer->getSize().y)});

        window.draw(uiSprite);
    }
}

void TitleScreen::Shutdown()
{
    _logger.Debug("Shutting down TitleScreen");
    ResourceManager& resourceManager = GetGame().GetResourceManager();

    // TODO: Loop over the screen resources instead of unloading them one by one
    resourceManager.UnloadResource("TitleScreen::BackgroundLayer");
    resourceManager.UnloadResource("TitleScreen::UILayer");
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

    // TODO: Loop over the clickable resources instead of doing this manually and call their onClick function
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
