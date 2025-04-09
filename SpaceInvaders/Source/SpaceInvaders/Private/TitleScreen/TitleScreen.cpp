// Copyright (c) Eric Jeker. All Rights Reserved.

#include "TitleScreen.h"

#include <GameScreen.h>
#include <SpaceInvaders.h>

TitleScreen::TitleScreen(SpaceInvaders& game)
    : Screen(game), _logger("TitleScreen", game.GetConfiguration().LogLevel),
      _guiManager(GetGame().GetResourceManager())
{
}

void TitleScreen::Activate()
{
    _logger.Debug("Activating TitleScreen");

    auto& game = GetGame();
    // Create a window instance from the game to fetch size
    const auto& window = game.GetWindow();

    const float centerX = window.getSize().x / 2.f;
    const float centerY = window.getSize().y / 2.f;

    // Create the render layers, everything will be rendered on these layers
    _backgroundLayer = std::make_unique<sf::RenderTexture>(window.getSize());
    _uiLayer = std::make_unique<sf::RenderTexture>(window.getSize());

    // Create title text
    _guiManager.AddText("Space Invaders", {centerX, centerY - 250.f}, 50, sf::Color::White, sf::Text::Bold);

    // Create Buttons
    _guiManager.AddButton("Play", {centerX, centerY}, 40);
    _guiManager.AddButton("Exit", {centerX, centerY + 100.f}, 30);
}

void TitleScreen::Update(const sf::Time& deltaTime)
{
    _particleSystem.Update(deltaTime);
    _guiManager.Update(deltaTime);
}

void TitleScreen::Render()
{
    sf::RenderWindow& window = GetGame().GetWindow();
    ResourceManager& resourceManager = GetGame().GetResourceManager();

    _backgroundLayer->clear();
    _uiLayer->clear();

    _particleSystem.Render(*_backgroundLayer);
    _guiManager.Render(*_uiLayer);

    window.draw(CreateRenderSprite(*_backgroundLayer));
    window.draw(CreateRenderSprite(*_uiLayer));
}

sf::Sprite TitleScreen::CreateRenderSprite(const sf::RenderTexture& renderTexture)
{
    const sf::Vector2f flippedScale(1.f, -1.f);
    const float textureHeight = static_cast<float>(renderTexture.getSize().y);

    sf::Sprite sprite(renderTexture.getTexture());
    sprite.setScale(flippedScale);
    sprite.setPosition({0.f, textureHeight});

    return sprite;
}

void TitleScreen::Shutdown()
{
    _logger.Debug("Shutting down TitleScreen");

    // TODO: remove entities
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
        auto& state = GetGame().GetState();
        // TODO: replace by MouseComponent
        state.mousePos.x = event.position.x;
        state.mousePos.y = event.position.y;
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
