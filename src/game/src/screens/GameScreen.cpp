#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include "GameScreen.hpp"
#include "Game.hpp"

GameScreen::GameScreen(const Game& game)
	: _game(game), _circle(100.f)
{
	_circle.setFillColor(sf::Color::Red);
	_circle.setPosition(sf::Vector2f(100.f, 100.f));
}
GameScreen::~GameScreen() = default;

void GameScreen::update() const
{
	_game.getWindow().draw(_circle);
}
