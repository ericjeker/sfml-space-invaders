// Copyright (c) Eric Jeker. All Rights Reserved.

#include "GameScreen.h"

#include <Configuration.h>
#include <SpaceInvaders.h>
#include <TimeTicker.h>
#include <TitleScreen.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game) : Screen(game), _logger("GameScreen", game.GetConfiguration().LogLevel), _playerController(game.GetWindow(), game.GetConfiguration()) {}

void GameScreen::Activate()
{
    _logger.Debug("Activating GameScreen");

    auto& game = GetGame();
    // Create a window instance from the game to fetch size
    const auto& window = game.GetWindow();

    const float centerX = window.getSize().x / 2.f;
    const float centerY = window.getSize().y / 2.f;

    // Create the render layers, everything will be rendered on these layers
    _backgroundLayer = std::make_unique<sf::RenderTexture>(window.getSize());
    _gameLayer = std::make_unique<sf::RenderTexture>(window.getSize());
    _uiLayer = std::make_unique<sf::RenderTexture>(window.getSize());

    // Load resources when the Screen is activated

    // Initialize the player controller
    _playerController.Initialize(_game.GetState().player);
}

void GameScreen::Shutdown()
{
    _logger.Debug("Shutting down GameScreen");
}

void GameScreen::Update(const sf::Time& deltaTime)
{
    if (GetGame().GetState().isPaused)
    {
        return;
    }

    _playerController.Update(deltaTime, _game.GetState().player);
}

void GameScreen::Render()
{
    auto& resourceManager = GetGame().GetResourceManager();
    auto& window = GetGame().GetWindow();

    _backgroundLayer->clear(sf::Color(0, 0, 0, 0));
    _gameLayer->clear(sf::Color(0, 0, 0, 0));
    _uiLayer->clear(sf::Color(0, 0, 0, 0));

    _playerController.Render(*_gameLayer, _game.GetState().player);

    window.draw(CreateRenderSprite(*_backgroundLayer));
    window.draw(CreateRenderSprite(*_gameLayer));
    window.draw(CreateRenderSprite(*_uiLayer));
}

// TODO: This is duplicated in TitleScreen.cpp
sf::Sprite GameScreen::CreateRenderSprite(const sf::RenderTexture& renderTexture)
{
    const sf::Vector2f flippedScale(1.f, -1.f);
    const float textureHeight = static_cast<float>(renderTexture.getSize().y);

    sf::Sprite sprite(renderTexture.getTexture());
    sprite.setScale(flippedScale);
    sprite.setPosition({0.f, textureHeight});

    return sprite;
}

void GameScreen::HandleEvents(const std::optional<sf::Event>& event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
        {
            GetGame().GetScreenManager().SetCurrentScreen<TitleScreen>();
        }
    }
    else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
    {
        std::shared_ptr<sf::CircleShape> circle =
            GetGame().GetResourceManager().GetResource<sf::CircleShape>("GameScreen::ClickDot");
        circle->setPosition(sf::Vector2f(mouseButtonPressed->position));
        circle->setFillColor(sf::Color::White);
    }
}
