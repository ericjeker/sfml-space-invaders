// Copyright (c) Eric Jeker. All Rights Reserved.

#include "PauseScreen/PauseScreen.h"

#include "SpaceInvaders.h"

#include "Commands/CommandId.h"
#include "Commands/QuitCommand.h"
#include "Commands/ResumeCommand.h"
#include "UI/Button.h"
#include "UI/Text.h"

PauseScreen::PauseScreen(SpaceInvaders& game)
	: Screen(game)
	, _logger("PauseScreen", game.GetConfiguration().LogLevel)
	, _commandRegistry(game.GetConfiguration())
	, _uiManager(_commandRegistry)
{
}

void PauseScreen::Activate()
{
	_logger.Debug("Activating PauseScreen");

	auto& game = GetGame();

	// Initialize the Command Registry
	_commandRegistry.Register(static_cast<int>(CommandId::ResumeGame), std::make_shared<ResumeCommand>(game));
	_commandRegistry.Register(static_cast<int>(CommandId::QuitGame), std::make_shared<QuitCommand>(game));

	CreateUI();
}

void PauseScreen::Update(const sf::Time& deltaTime)
{
	_uiManager.Update(deltaTime);
}

void PauseScreen::Render()
{
	sf::RenderWindow& window = GetGame().GetWindow();

	_backgroundLayer.clear(sf::Color(0, 0, 0, 0));
	_uiLayer.clear(sf::Color(0, 0, 0, 0));

	_uiManager.Render(_uiLayer);

	window.draw(CreateRenderSprite(_backgroundLayer));
	window.draw(CreateRenderSprite(_uiLayer));
}

sf::Sprite PauseScreen::CreateRenderSprite(const sf::RenderTexture& renderTexture)
{
	const sf::Vector2f flippedScale(1.f, -1.f);
	const float textureHeight = static_cast<float>(renderTexture.getSize().y);

	sf::Sprite sprite(renderTexture.getTexture());
	sprite.setScale(flippedScale);
	sprite.setPosition({0.f, textureHeight});

	return sprite;
}

void PauseScreen::Shutdown()
{
	_logger.Debug("Shutting down");
}

void PauseScreen::HandleEvents(const std::optional<sf::Event>& event)
{
	if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
	{
		OnKeyPressed(*keyPressed);
	}

	_uiManager.HandleEvents(event);
}

void PauseScreen::OnKeyPressed(sf::Event::KeyPressed key_pressed)
{
	if (key_pressed.scancode == sf::Keyboard::Scancode::Escape)
	{
		_commandRegistry.Execute(static_cast<int>(CommandId::ResumeGame));
	}
}

void PauseScreen::CreateUI()
{
	auto& game = GetGame();

	// Create a window instance from the game to fetch size
	const auto& window = game.GetWindow();

	const float centerX = window.getSize().x / 2.f;
	const float centerY = window.getSize().y / 2.f;

	// Create the render layers, everything will be rendered on these layers
	_backgroundLayer = sf::RenderTexture(window.getSize());
	_uiLayer = sf::RenderTexture(window.getSize());

	// Create Pause text
	std::shared_ptr<sf::Font> font = game.GetResourceManager().GetResource<sf::Font>("DefaultFont");
	std::unique_ptr<UIComponent> text = std::make_unique<Text>(font, "Pause", 50, sf::Color::White);
	text->SetPosition({centerX, centerY - 200});
	_uiManager.AddComponent(std::move(text));

	// Play button
	auto resumeButton = std::make_unique<Button>(font, "Resume", 40, sf::Color::Black, static_cast<int>(CommandId::ResumeGame));
	resumeButton->SetSize({300, 80});
	resumeButton->SetPosition({centerX - 150, centerY - 40});
	resumeButton->SetOutlineColor(sf::Color::White);
	_uiManager.AddComponent(std::move(resumeButton));

	// Exit button
	auto quitButton = std::make_unique<Button>(font, "Quit", 30, sf::Color::White, static_cast<int>(CommandId::QuitGame));
	quitButton->SetSize({200, 50});
	quitButton->SetPosition({centerX - 100, centerY + 75});
	quitButton->SetOutlineColor(sf::Color::Transparent);
	_uiManager.AddComponent(std::move(quitButton));
}
