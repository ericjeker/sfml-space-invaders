// Copyright (c) Eric Jeker. All Rights Reserved.

#include <Configuration.h>
#include <TimeTicker.h>
#include <GameScreen.h>
#include <SpaceInvaders.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game)
    : _Game(game), _Logger("GameScreen", game.GetConfiguration().LogLevel), _Circle(100.f)
{
    _Circle.setFillColor(sf::Color::Red);
    _Circle.setPosition(sf::Vector2f(100.f, 100.f));
}

GameScreen::~GameScreen() = default;

void GameScreen::Update(const TimeTicker& timeTicker)
{
    if (_Game.GetState().IsPaused)
    {
        return;
    }

    _Game.GetState().Score++;
}

void GameScreen::Render() const
{
    _Game.GetWindow().draw(_Circle);
}
