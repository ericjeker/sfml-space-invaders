// Copyright (c) Eric Jeker. All Rights Reserved.

#include <Configuration.h>
#include <GameScreen.h>
#include <SpaceInvaders.h>
#include <TimeTicker.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game)
    : Screen(game), _logger("GameScreen", game.GetConfiguration().LogLevel), _Circle(100.f)
{
}

void GameScreen::Activate()
{
    Configuration configuration = GetGame().GetConfiguration();

    /** Load resources when the Screen is activated */
    const auto circle = new sf::CircleShape(100.f);
    circle->setFillColor(sf::Color::Red);
    circle->setOutlineColor(sf::Color::Blue);
    circle->setOutlineThickness(5.f);
    circle->setOrigin({circle->getRadius(), circle->getRadius()});
    circle->setPosition({configuration.WindowSize.x / 2.0f, configuration.WindowSize.y / 2.0f});
    GetGame().GetResourceManager().SetResource<sf::CircleShape>("circle", circle);
}

void GameScreen::Shutdown()
{
    GetGame().GetResourceManager().UnloadResource("circle");
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
    const sf::CircleShape& circle = GetGame().GetResourceManager().GetResource<sf::CircleShape>("circle");
    GetGame().GetWindow().draw(circle);
}
