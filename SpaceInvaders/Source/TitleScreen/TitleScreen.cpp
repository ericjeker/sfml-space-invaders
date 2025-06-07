// Copyright (c) Eric Jeker. All Rights Reserved.

#include "TitleScreen/TitleScreen.h"

#include "SpaceInvaders.h"

#include "Commands/ExitCommand.h"
#include "Commands/PlayCommand.h"
#include "Commands/CommandId.h"
#include "GameScreen/GameScreen.h"
#include "UI/Button.h"
#include "UI/Text.h"

TitleScreen::TitleScreen(SpaceInvaders& game)
	: Screen(game)
	, _logger("TitleScreen", game.GetConfiguration().LogLevel)
	, _commandRegistry(game.GetConfiguration())
	, _uiManager(_commandRegistry)
	, _particleConstellation(game.GetConfiguration())
{
}

void TitleScreen::Activate()
{
	_logger.Debug("Activating TitleScreen");

	auto& game = GetGame();

	// Initialize the Command Registry
	_commandRegistry.Register(static_cast<int>(CommandId::StartGame), std::make_shared<PlayCommand>(game));
	_commandRegistry.Register(static_cast<int>(CommandId::Quit), std::make_shared<ExitCommand>(game));

	CreateUI();

	// Initialize the particle system with 1000 particles
	_particleConstellation.Initialize(1000);
}

void TitleScreen::Update(const sf::Time& deltaTime)
{
	_particleConstellation.Update(deltaTime);
	_uiManager.Update(deltaTime);
}

void TitleScreen::Render()
{
	sf::RenderWindow& window = GetGame().GetWindow();

	_backgroundLayer->clear(sf::Color(0, 0, 0, 0));
	_uiLayer->clear(sf::Color(0, 0, 0, 0));

	_particleConstellation.Render(*_backgroundLayer);
	_uiManager.Render(*_uiLayer);

	window.draw(CreateRenderSprite(*_backgroundLayer));
	window.draw(CreateRenderSprite(*_uiLayer));
}

void TitleScreen::Shutdown()
{
	_logger.Debug("Shutting down TitleScreen");

	// TODO: remove entities
}

void TitleScreen::HandleEvents(const std::optional<sf::Event>& event)
{
	if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
	{
		OnKeyPressed(*keyPressed);
	}

	_uiManager.HandleEvents(event);
}

void TitleScreen::OnKeyPressed(const sf::Event::KeyPressed& keyPressed)
{
	if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
	{
		_commandRegistry.Execute(static_cast<int>(CommandId::Quit));
	}
}

sf::Sprite TitleScreen::CreateRenderSprite(const sf::RenderTexture& renderTexture)
{
	const sf::Vector2f flippedScale(1.f, -1.f);
	const float textureHeight = static_cast<float>(renderTexture.getSize().y);

	sf::Sprite sprite(renderTexture.getTexture());
	sprite.setScale(flippedScale);
	sprite.setPosition({0.f, textureHeight});

	return sprite;
}

void TitleScreen::CreateUI()
{
	auto& game = GetGame();

	// Create a window instance from the game to fetch size
	const auto& window = game.GetWindow();

	const float centerX = window.getSize().x / 2.f;
	const float centerY = window.getSize().y / 2.f;

	// Create the render layers, everything will be rendered on these layers
	_backgroundLayer = std::make_unique<sf::RenderTexture>(window.getSize());
	_uiLayer = std::make_unique<sf::RenderTexture>(window.getSize());

	// Create title text
	std::shared_ptr<sf::Font> font = game.GetResourceManager().GetResource<sf::Font>("DefaultFont");
	std::unique_ptr<UIComponent> text = std::make_unique<Text>(font, "Space Invaders", 50, sf::Color::White);
	text->SetPosition({centerX, centerY - 200});
	_uiManager.AddComponent(std::move(text));

	// Play button
	auto playButton = std::make_unique<Button>(font, "Play", 40, sf::Color::Black, static_cast<int>(CommandId::StartGame));
	playButton->SetSize({300, 80});
	playButton->SetPosition({centerX - 150, centerY - 40});
	playButton->SetOutlineColor(sf::Color::White);
	_uiManager.AddComponent(std::move(playButton));

	// Exit button
	auto exitButton = std::make_unique<Button>(font, "Exit", 30, sf::Color::White, static_cast<int>(CommandId::Quit));
	exitButton->SetSize({200, 50});
	exitButton->SetPosition({centerX - 100, centerY + 75});
	exitButton->SetOutlineColor(sf::Color::Transparent);

	_uiManager.AddComponent(std::move(exitButton));
}
