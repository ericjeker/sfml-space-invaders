// Copyright (c) Eric Jeker. All Rights Reserved.

#include <Configuration.h>
#include <TimeTicker.h>
#include <GameScreen.h>
#include <SpaceInvaders.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game)
    : _Logger("GameScreen", game.GetConfiguration().LogLevel), _Game(game), _Circle(100.f)
{
}

GameScreen::~GameScreen() = default;

void GameScreen::Activate()
{
    Configuration configuration = _Game.GetConfiguration();

    /** Load resources when the Screen is activated */
    const auto circle = new sf::CircleShape(100.f);
    circle->setFillColor(sf::Color::Red);
    circle->setOutlineColor(sf::Color::Blue);
    circle->setOutlineThickness(5.f);
    circle->setOrigin({circle->getRadius(), circle->getRadius()});
    circle->setPosition({configuration.WindowSize.x / 2.0f, configuration.WindowSize.y / 2.0f});
    _Game.GetResourceManager().SetResource<sf::CircleShape>("circle", circle);
}

void GameScreen::Shutdown()
{
    _Game.GetResourceManager().UnloadResource("circle");
}

void GameScreen::Update(const TimeTicker& timeTicker)
{
    if (_Game.GetState().IsPaused)
    {
        return;
    }
}

void GameScreen::Render() const
{
    /** Draw resources */
    const sf::CircleShape& circle = _Game.GetResourceManager().GetResource<sf::CircleShape>("circle");
    _Game.GetWindow().draw(circle);
}
