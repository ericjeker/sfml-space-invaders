#include <SFML/Graphics.hpp>

#include "Logger.hpp"
#include "Game.hpp"

Game::Game(sf::RenderWindow& window)
	: _window(window), _logger("Game", Logger::LogLevel::Info), _gameScreen(*this) {}

Game::~Game() = default;

void Game::run() const
{
	_logger.info("Game started");

	while (_window.isOpen())
	{
		_window.handleEvents(
			[this](const sf::Event::Closed& event) { this->onClose(event); },
			[this](const sf::Event::KeyPressed& event) { this->onKeyPressed(event); });

		update();
	}
}

sf::RenderWindow& Game::getWindow() const
{
	return _window;
}

void Game::update() const
{
	_window.clear();
	_gameScreen.update();
	_window.display();
}

void Game::onClose(const sf::Event::Closed&) const
{
	_window.close();
}

void Game::onKeyPressed(const sf::Event::KeyPressed& keyPressed) const
{
	if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
		_window.close();
}
