// Copyright (c) Eric Jeker. All Rights Reserved.

#include "SpaceInvaders.h"

#include <GameScreen/GameScreen.h>
#include <TitleScreen/TitleScreen.h>

#include <SFML/Graphics.hpp>

/**
 * Initialize the game. This is the place where we want to:
 *
 * - add all the game screens
 * - initialize the managers (sounds, particles, physics, network, settings, storage, inputs, resources)
 * - catch some global events (resize, focus, exit)
 */
SpaceInvaders::SpaceInvaders(const sf::RenderWindow& window, const Configuration& configuration)
    : Game(window, configuration)
    , _logger("SpaceInvaders", configuration.LogLevel)
{
    _logger.Debug("Game initialized");

    // TODO: Load saved settings

    // TODO: Load saved state

    // Initialize global resources
    auto font = std::make_shared<sf::Font>("Assets/Fonts/Orbitron/static/Orbitron-Regular.ttf");
    GetResourceManager().SetResource<sf::Font>("DefaultFont", font);
    auto clickDot = std::make_shared<sf::CircleShape>(2.f);
    GetResourceManager().SetResource<sf::CircleShape>("Global::ClickDot", clickDot);

    // TODO: Initialize physics world and add to game

    // Initialize Game Screens, all screen receive the game itself in parameter
    _screenManager.AddScreen<TitleScreen>(*this);
    _screenManager.AddScreen<GameScreen>(*this);

    // Set and Activate the initial screen
    _screenManager.SetCurrentScreen<TitleScreen>();
}

/**
 * Run the game, we start the Update loop.
 * This will keep running as long as the window is open.
 */
void SpaceInvaders::Run()
{
    _logger.Debug("Game started");

    sf::Clock clock;

    // Starting the game loop
    while (_window.isOpen())
    {
        while (const std::optional<sf::Event> event = _window.pollEvent())
        {
            HandleEvents(event);
        }

        sf::Time deltaTime = clock.restart();
        Update(deltaTime);
        Render();
    }
}

void SpaceInvaders::Exit()
{
    // We shut down the screen to unload the resources
    _screenManager.CleanUp();
    _resourceManager.CleanUp();
    _window.close();
}

void SpaceInvaders::HandleEvents(const std::optional<sf::Event>& event)
{
    // We first let the current screen handle the event
    _screenManager.HandleEvents(event);

    if (event->is<sf::Event::Closed>())
    {
        OnClose();
    }
    else if (event->is<sf::Event::FocusLost>())
    {
        OnFocusLost();
    }
    else if (event->is<sf::Event::FocusGained>())
    {
        OnFocusGained();
    }
}

void SpaceInvaders::OnFocusLost()
{
    _logger.Debug("Focus lost");
    _gameState.isPaused = true;
}

void SpaceInvaders::OnFocusGained()
{
    _logger.Debug("Focus gained");
    _gameState.isPaused = false;
}
void SpaceInvaders::OnResize()
{
    _logger.Debug("Window resized");
}

void SpaceInvaders::OnClose()
{
    _logger.Debug("Shutting down SpaceInvaders");
    Exit();
}

void SpaceInvaders::Update(const sf::Time& deltaTime) const
{
    // Delegate the update to the current screen
    _screenManager.Update(deltaTime);
}

void SpaceInvaders::Render() const
{
    // Clean-up the window and delegate the rendering to the current screen
    _window.clear();
    _screenManager.Render();
    _window.display();
}
