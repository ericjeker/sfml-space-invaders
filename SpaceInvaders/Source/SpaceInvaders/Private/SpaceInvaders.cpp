// Copyright (c) Eric Jeker. All Rights Reserved.

#include "SpaceInvaders.h"

#include <GameScreen.h>
#include <TitleScreen.h>

#include <SFML/Graphics.hpp>

/**
 * Initialize the game. This is the place where we want to:
 *
 * - add all the game screens
 * - initialize the managers (sounds, particles, physics, network, settings, storage, inputs, resources)
 * - catch some global events (resize, focus, exit)
 */
SpaceInvaders::SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration)
    : _screenManager(configuration), _configuration(configuration), _logger("SpaceInvaders", configuration.LogLevel),
      _window(window)
{
    _logger.Debug("Game initialized");

    // TODO: Load saved state

    // TODO: Load saved settings

    // TODO: Initialize global resources

    // TODO: Initialize physics world

    // TODO: Initialize ECS registry

    // Initialize Game Screens
    _screenManager.AddScreen<TitleScreen>(*this);
    _screenManager.AddScreen<GameScreen>(*this);

    // Set and Activate the initial screen
    _screenManager.SetCurrentScreen<TitleScreen>();
    _screenManager.Activate();
}

/**
 * Run the game, we start the Update loop. This will keep running as long as the window is open.
 */
void SpaceInvaders::Run()
{
    _logger.Debug("Game started");

    sf::Clock clock;
    TimeTicker timeTicker;

    while (_window.isOpen())
    {
        const sf::Time frameTime = clock.restart();
        timeTicker.accumulator += frameTime;
        timeTicker.elapsedTime += frameTime;

        HandleEvents();

        while (timeTicker.accumulator >= timeTicker.timeStep)
        {
            timeTicker.delta = timeTicker.accumulator - timeTicker.timeStep;
            Update(timeTicker);
            timeTicker.accumulator -= timeTicker.timeStep;
        }

        Render();
    }
}

sf::RenderWindow& SpaceInvaders::GetWindow() const
{
    return _window;
}

/**
 * TODO: This ultimately will be replace by EnTT
 */
GameState& SpaceInvaders::GetState()
{
    return _gameState;
}

const Configuration& SpaceInvaders::GetConfiguration() const
{
    return _configuration;
}

ResourceManager& SpaceInvaders::GetResourceManager()
{
    return _resourceManager;
}

void SpaceInvaders::HandleEvents()
{
    _screenManager.HandleEvents();
}

void SpaceInvaders::Update(const TimeTicker& timeTicker) const
{
    _screenManager.Update(timeTicker);
}

void SpaceInvaders::Render() const
{
    _window.clear();
    _screenManager.Render();
    _window.display();
}

void SpaceInvaders::Exit()
{
    // We shut down the screen to unload the resources
    _screenManager.CleanUp();
    _resourceManager.CleanUp();
    _window.close();
}
