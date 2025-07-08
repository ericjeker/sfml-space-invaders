// Copyright (c) Eric Jeker. All Rights Reserved.

#include "GameScreen/GameScreen.h"

#include "Configuration.h"
#include "SpaceInvaders.h"

#include "Commands/PauseCommand.h"
#include "Commands/QuitCommand.h"
#include "Systems/BulletSystem.h"
#include "Systems/EnemySystem.h"
#include "Systems/PlayerController.h"
#include "TitleScreen/TitleScreen.h"
#include "UI/Text.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameScreen::GameScreen(SpaceInvaders& game)
	: Screen(game)
	, _logger("GameScreen", game.GetEngineContext().GetConfiguration().CurrentLogLevel)
	, _commandRegistry(std::make_unique<CommandRegistry>(game.GetEngineContext().GetConfiguration()))
	, _uiManager(std::make_unique<UIManager>(*_commandRegistry))
{
}

void GameScreen::Activate()
{
	_logger.Debug("Activating GameScreen");

	auto& game = GetGame();

	// Create a window instance from the game to fetch size
	const auto& window = game.GetEngineContext().GetWindow();

	// Initialization
	InitializeCommands(game);
	InitializeRenderLayers(window);
	InitializeUI();

	// Create the textures and shapes
	_playerRectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(100.f, 40.f));
	_playerRectangle->setFillColor(sf::Color::White);

	_enemyRectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(100.f, 40.f));
	_enemyRectangle->setFillColor(sf::Color::Blue);

	// TODO: ObjectPool is needed
	_bulletShape = std::make_unique<sf::CircleShape>(10.f);
	_bulletShape->setFillColor(sf::Color::Red);
	_bulletShape->setOrigin({5.f, 5.f});

	// Initialize the enemies
	// EnemySystem::Initialize(_enemies);

	// Initialize the player controller
	PlayerController::Initialize(_player, sf::Vector2f(window.getSize().x / 2.f, window.getSize().y - 200.f));
	BulletSystem::Initialize(_bullets);
}

void GameScreen::InitializeRenderLayers(const sf::RenderWindow& window)
{
	_uiSettings.antiAliasingLevel = 4;

	_backgroundLayer = sf::RenderTexture(window.getSize(), _uiSettings);
	_gameLayer = sf::RenderTexture(window.getSize(), _uiSettings);
	_uiLayer = sf::RenderTexture(window.getSize(), _uiSettings);
}

void GameScreen::InitializeCommands(SpaceInvaders& game)
{
	_commands.emplace("GameScreen::Pause", _commandRegistry->Register(std::make_shared<PauseCommand>(game)));
	_commands.emplace("GameScreen::Quit", _commandRegistry->Register(std::make_shared<QuitCommand>(game)));
}

void GameScreen::InitializeUI() const
{
	const auto& game = GetGame();

	// Create a window instance from the game to fetch size
	const auto& window = game.GetEngineContext().GetWindow();

	const float centerX = window.getSize().x / 2.f;

	// TODO: Add the current score
	std::shared_ptr<sf::Font> font = game.GetEngineContext().GetResourceManager().GetResource<sf::Font>("Orbitron");
	std::unique_ptr<UIComponent> text = std::make_unique<Text>(font, "Score: 0", 50, sf::Color::White);
	text->SetPosition({centerX, 50});
	_uiManager->AddComponent(std::move(text));

	// TODO: Add the high score
	// TODO: Add the number of lives
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
			_commandRegistry->Execute(_commands["GameScreen::Pause"]);
		}
	}
}

void GameScreen::Update(const sf::Time& deltaTime)
{
	if (GetGame().GetState().isPaused)
	{
		return;
	}

	const auto windowSize = GetGame().GetEngineContext().GetWindow().getSize();

	const PlayerController::UpdateContext context = {.deltaTime = deltaTime, .screenBounds = windowSize};
	PlayerController::Update(context, _player, _bullets);

	BulletSystem::Update(deltaTime, _bullets);
}

void GameScreen::Render()
{
	auto& window = GetGame().GetEngineContext().GetWindow();

	_backgroundLayer.clear(sf::Color(0, 0, 0, 0));
	_gameLayer.clear(sf::Color(0, 0, 0, 0));
	_uiLayer.clear(sf::Color(0, 0, 0, 0));

	_uiManager->Render(_uiLayer);
	PlayerController::Render(_gameLayer, _player, *_playerRectangle);
	BulletSystem::Render(_gameLayer, _bullets, *_bulletShape);

	_backgroundLayer.display();
	_gameLayer.display();
	_uiLayer.display();

	window.draw(sf::Sprite(_backgroundLayer.getTexture()));
	window.draw(sf::Sprite(_gameLayer.getTexture()));
	window.draw(sf::Sprite(_uiLayer.getTexture()));
}
