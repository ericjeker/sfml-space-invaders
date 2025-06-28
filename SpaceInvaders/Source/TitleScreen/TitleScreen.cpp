// Copyright (c) Eric Jeker. All Rights Reserved.

#include "TitleScreen/TitleScreen.h"

#include "SpaceInvaders.h"

#include "Commands/CommandId.h"
#include "Commands/ExitCommand.h"
#include "Commands/PlayCommand.h"
#include "GameScreen/GameScreen.h"
#include "UI/Button.h"
#include "UI/RoundedRectangleShape.h"
#include "UI/Text.h"

#include <cmath>
#include <iostream>

TitleScreen::TitleScreen(SpaceInvaders& game)
	: Screen(game)
	, _logger("TitleScreen", game.GetConfiguration().LogLevel)
	, _commandRegistry(game.GetConfiguration())
	, _uiManager(_commandRegistry)
	, _particleConstellation(game.GetConfiguration(), sf::Texture("Assets/Textures/Particle.png"))
{
}

void TitleScreen::Activate()
{
	_logger.Debug("Activating TitleScreen");

	auto& game = GetGame();

	// Initialize the Command Registry
	_commandRegistry.Register(static_cast<int>(CommandId::StartGame), std::make_shared<PlayCommand>(game));
	_commandRegistry.Register(static_cast<int>(CommandId::Exit), std::make_shared<ExitCommand>(game));

	// Create the UI Components
	CreateUI();

	// Initialize the particle system with 1000 particles
	_particleConstellation.Initialize(500);
}

void TitleScreen::Update(const sf::Time& deltaTime)
{
	_particleConstellation.Update(deltaTime);
	_uiManager.Update(deltaTime);
}

void TitleScreen::Render()
{
	sf::RenderWindow& window = GetGame().GetWindow();

	_backgroundLayer.clear(sf::Color(0, 0, 0, 0));
	_uiLayer.clear(sf::Color(0, 0, 0, 0));

	_particleConstellation.Render(_backgroundLayer);
	_uiManager.Render(_uiLayer);

	_backgroundLayer.display();
	_uiLayer.display();

	window.draw(sf::Sprite(_backgroundLayer.getTexture()));
	window.draw(sf::Sprite(_uiLayer.getTexture()));
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
		_commandRegistry.Execute(static_cast<int>(CommandId::Exit));
	}
}

void TitleScreen::CreateUI()
{
	auto& game = GetGame();

	// Create a window instance from the game to fetch size
	const auto& window = game.GetWindow();

	const float centerX = window.getSize().x / 2.f;
	const float centerY = window.getSize().y / 2.f;

	// Create the render layers, everything will be rendered on these layers
	_uiSettings.antiAliasingLevel = 4;

	_backgroundLayer = sf::RenderTexture(window.getSize(), _uiSettings);
	_uiLayer = sf::RenderTexture(window.getSize(), _uiSettings);

	// Create title text
	std::shared_ptr<sf::Font> font = game.GetResourceManager().GetResource<sf::Font>("DefaultFont");
	std::unique_ptr<UIComponent> text = std::make_unique<Text>(font, "Space Invaders", 50, sf::Color::White);
	text->SetPosition({centerX, centerY - 200});
	_uiManager.AddComponent(std::move(text));

	// Play button
	auto playButton =
		std::make_unique<Button>(font, "Play", 40, sf::Color::Black, static_cast<int>(CommandId::StartGame));
	playButton->SetSize({300, 80});
	playButton->SetOrigin({playButton->GetSize().x / 2.f, playButton->GetSize().y / 2.f});
	playButton->SetPosition({centerX, centerY});
	playButton->SetOutlineFillColor(sf::Color::White);
	playButton->SetOutlineColor(sf::Color::White);
	playButton->SetOutlineThickness(4.f);
	playButton->SetOutlineRadius(10.f);
	playButton->SetOnHover(
		[](Button& btn)
		{ btn.GetAnimator().AddTracker([&](float r) { btn.SetScale({r, r}); }, 1.0f, 1.1f, 0.25f, false); });
	playButton->SetOnHoverExit(
		[](Button& btn)
		{ btn.GetAnimator().AddTracker([&](float r) { btn.SetScale({r, r}); }, 1.1f, 1.0f, 0.25f, false); });
	_uiManager.AddComponent(std::move(playButton));

	// Exit button
	auto exitButton = std::make_unique<Button>(font, "Exit", 30, sf::Color::White, static_cast<int>(CommandId::Exit));
	exitButton->SetSize({200, 50});
	exitButton->SetOrigin({exitButton->GetSize().x / 2.f, exitButton->GetSize().y / 2.f});
	exitButton->SetPosition({centerX, centerY + 100});
	exitButton->SetOutlineColor(sf::Color::Transparent);
	exitButton->SetOutlineFillColor(sf::Color::Black);
	exitButton->SetOutlineColor(sf::Color::White);
	exitButton->SetOutlineThickness(4.f);
	exitButton->SetOutlineRadius(8.f);
	exitButton->SetOnHover(
		[](Button& btn)
		{ btn.GetAnimator().AddTracker([&](float r) { btn.SetScale({r, r}); }, 1.0f, 1.1f, 0.25f, false); });
	exitButton->SetOnHoverExit(
		[](Button& btn)
		{ btn.GetAnimator().AddTracker([&](float r) { btn.SetScale({r, r}); }, 1.1f, 1.0f, 0.25f, false); });
	_uiManager.AddComponent(std::move(exitButton));
}
