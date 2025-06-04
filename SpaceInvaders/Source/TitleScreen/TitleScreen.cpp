// Copyright (c) Eric Jeker. All Rights Reserved.

#include "TitleScreen/TitleScreen.h"
#include "SpaceInvaders.h"
#include "GameScreen/GameScreen.h"

#include "Commands/ExitCommand.h"
#include "Commands/PlayCommand.h"

TitleScreen::TitleScreen(SpaceInvaders& game)
    : Screen(game)
    , _logger("TitleScreen", game.GetConfiguration().LogLevel)
    , _commandRegistry(game.GetConfiguration())
    , _guiManager(GetGame().GetResourceManager(), _commandRegistry)
    , _particleConstellation(game.GetConfiguration())
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

    // Initialize the Command Registry
    _commandRegistry.Register(1, std::make_shared<PlayCommand>(game));
    _commandRegistry.Register(2, std::make_shared<ExitCommand>(game));

    // Create title text
    _guiManager.AddText("Space Invaders", {centerX, centerY - 250.f}, 50, sf::Color::White, sf::Text::Bold);

    // Create Buttons
    _guiManager.AddButton("Play", {centerX, centerY}, 40, 1);
    _guiManager.AddButton("Exit", {centerX, centerY + 100.f}, 30, 2);

    // Initialize the particle system with 1000 particles
    _particleConstellation.Initialize(1000);
}

void TitleScreen::Update(const sf::Time& deltaTime)
{
    _particleConstellation.Update(deltaTime);
    _guiManager.Update(deltaTime);
}

void TitleScreen::Render()
{
    sf::RenderWindow& window = GetGame().GetWindow();

    _backgroundLayer->clear(sf::Color(0, 0, 0, 0));
    _uiLayer->clear(sf::Color(0, 0, 0, 0));

    _particleConstellation.Render(*_backgroundLayer);
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

void TitleScreen::OnMousePressed(const sf::Event::MouseButtonPressed& event)
{
    _logger.Debug(std::format("OnMousePressed at ({}, {})", event.position.x, event.position.y));
    _guiManager.OnMousePressed(event);
}
