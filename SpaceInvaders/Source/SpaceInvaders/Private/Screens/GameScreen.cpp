// Copyright (c) Eric Jeker. All Rights Reserved.

#include "GameScreen.h"

#include <Configuration.h>
#include <SpaceInvaders.h>
#include <TimeTicker.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game)
    : Screen(game), _logger("GameScreen", game.GetConfiguration().LogLevel), _circle(100.f)
{
}

void GameScreen::Activate()
{
    Configuration configuration = GetGame().GetConfiguration();

    /** Load resources when the Screen is activated */
    auto* circle = new sf::CircleShape(100.f);
    circle->setFillColor(sf::Color::Red);
    circle->setOutlineColor(sf::Color::Blue);
    circle->setOutlineThickness(5.f);
    circle->setOrigin({circle->getRadius(), circle->getRadius()});
    circle->setPosition({configuration.WindowSize.x / 2.0f, configuration.WindowSize.y / 2.0f});
    GetGame().GetResourceManager().SetResource<sf::CircleShape>("GameScreen::Circle", std::shared_ptr<sf::CircleShape>(circle));
}

void GameScreen::Shutdown()
{
    GetGame().GetResourceManager().UnloadResource("GameScreen::Circle");
}

void GameScreen::Update(const TimeTicker& timeTicker)
{
    if (GetGame().GetState().IsPaused)
    {
        return;
    }
}

void GameScreen::Render() const
{
    /** Draw resources */
    std::shared_ptr<sf::CircleShape> circle = GetGame().GetResourceManager().GetResource<sf::CircleShape>("GameScreen::Circle");
    GetGame().GetWindow().draw(*circle);
}

void GameScreen::HandleEvents()
{

}