// Copyright (c) Eric Jeker. All Rights Reserved.

#include "GameScreen.h"

#include <Configuration.h>
#include <SpaceInvaders.h>
#include <TimeTicker.h>
#include <TitleScreen.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game)
    : Screen(game), _logger("GameScreen", game.GetConfiguration().LogLevel)
{
}

void GameScreen::Activate()
{
    _logger.Debug("Activating GameScreen");

    Configuration configuration = GetGame().GetConfiguration();

    /** Load resources when the Screen is activated */
    std::shared_ptr<sf::CircleShape> circle = std::make_shared<sf::CircleShape>(3.f);
    circle->setFillColor(sf::Color::White);
    circle->setOrigin({circle->getRadius(), circle->getRadius()});
    circle->setPosition({-1.f, -1.f});
    GetGame().GetResourceManager().SetResource<sf::CircleShape>("GameScreen::ClickDot", std::shared_ptr<sf::CircleShape>(circle));
}

void GameScreen::Shutdown()
{
    _logger.Debug("Shutting down GameScreen");
    GetGame().GetResourceManager().UnloadResource("GameScreen::ClickDot");
}

void GameScreen::Update(const TimeTicker& timeTicker)
{
    if (GetGame().GetState().isPaused)
    {
        return;
    }
}

void GameScreen::Render() const
{
    /** Draw resources */
    std::shared_ptr<sf::CircleShape> circle = GetGame().GetResourceManager().GetResource<sf::CircleShape>("GameScreen::ClickDot");
    GetGame().GetWindow().draw(*circle);

    auto color = circle->getFillColor();
    color.a = color.a * 0.98f;
    circle->setFillColor(color);
}

void GameScreen::HandleEvents(const std::optional<sf::Event>& event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
        {
            GetGame().GetScreenManager().SetCurrentScreen<TitleScreen>();
        }
    } else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
    {
        std::shared_ptr<sf::CircleShape> circle = GetGame().GetResourceManager().GetResource<sf::CircleShape>("GameScreen::ClickDot");
        circle->setPosition(sf::Vector2f(mouseButtonPressed->position));
        circle->setFillColor(sf::Color::White);
    }
}