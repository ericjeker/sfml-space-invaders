// Copyright (c) Eric Jeker. All Rights Reserved.

#include "GameScreen/GameScreen.h"

#include "Configuration.h"
#include "SpaceInvaders.h"

#include "Commands/CommandId.h"
#include "Commands/PauseCommand.h"
#include "Commands/QuitCommand.h"
#include "TitleScreen/TitleScreen.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game)
	: Screen(game)
	, _logger("GameScreen", game.GetEngineContext().GetConfiguration().LogLevel)
	, _playerController(game.GetEngineContext().GetWindow(), game.GetEngineContext().GetConfiguration())
	, _bulletSystem(game.GetEngineContext().GetConfiguration())
	, _commandRegistry(game.GetEngineContext().GetConfiguration())
{
}

void GameScreen::Activate()
{
	_logger.Debug("Activating GameScreen");

	auto& game = GetGame();

	// Create a window instance from the game to fetch size
	const auto& window = game.GetEngineContext().GetWindow();

	// Initialize the Command Registry
	_commandRegistry.Register(static_cast<int>(CommandId::PauseGame), std::make_shared<PauseCommand>(game));
	_commandRegistry.Register(static_cast<int>(CommandId::QuitGame), std::make_shared<QuitCommand>(game));

	// Create the render layers, everything will be rendered on these layers
	_uiSettings.antiAliasingLevel = 4;

	_backgroundLayer = sf::RenderTexture(window.getSize(), _uiSettings);
	_gameLayer = sf::RenderTexture(window.getSize(), _uiSettings);
	_uiLayer = sf::RenderTexture(window.getSize(), _uiSettings);

	// Load resources when the Screen is activated

	// Initialize the player controller
	_playerController.Initialize(_game.GetState().player);
	_bulletSystem.Initialize();
}

void GameScreen::Shutdown()
{
	_logger.Debug("Shutting down GameScreen");
}

void GameScreen::HandleEvents(const std::optional<sf::Event>& event)
{
	if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
		{
			_commandRegistry.Execute(static_cast<int>(CommandId::PauseGame));
		}
	}
}

void GameScreen::Update(const sf::Time& deltaTime)
{
	if (GetGame().GetState().isPaused)
	{
		return;
	}

	_playerController.Update(deltaTime, _game.GetState().player);
	_bulletSystem.Update(deltaTime, _game.GetState().bullets);
}

void GameScreen::Render()
{
	auto& window = GetGame().GetEngineContext().GetWindow();

	_backgroundLayer.clear(sf::Color(0, 0, 0, 0));
	_gameLayer.clear(sf::Color(0, 0, 0, 0));
	_uiLayer.clear(sf::Color(0, 0, 0, 0));

	_playerController.Render(_gameLayer, _game.GetState().player);
	_bulletSystem.Render(_gameLayer, _game.GetState().bullets);

	_backgroundLayer.display();
	_gameLayer.display();
	_uiLayer.display();

	window.draw(sf::Sprite(_backgroundLayer.getTexture()));
	window.draw(sf::Sprite(_gameLayer.getTexture()));
	window.draw(sf::Sprite(_uiLayer.getTexture()));
}

