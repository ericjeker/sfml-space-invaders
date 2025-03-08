#pragma once
#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <SFML/Graphics.hpp>

class Game;

class GameScreen {
public:
	explicit GameScreen(const Game &game);
	~GameScreen();
	void update() const;
private:
	const Game& _game;
	sf::CircleShape _circle;
};

#endif