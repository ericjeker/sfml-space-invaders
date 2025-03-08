#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "GameScreen.hpp"
#include "Logger.hpp"

class Game
{
public:
    explicit Game(sf::RenderWindow& window);
    ~Game();
    void run() const;
    sf::RenderWindow& getWindow() const;

private:
    sf::RenderWindow& _window;
    Logger _logger;
    GameScreen _gameScreen;

private:
    void pollEvents() const;
    void update() const;
    void onClose(const sf::Event::Closed&) const;
    void onKeyPressed(const sf::Event::KeyPressed& keyPressed) const;
};

#endif
