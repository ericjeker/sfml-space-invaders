// Copyright (c) Eric Jeker. All Rights Reserved.

#include "SpaceInvaders.h"

#include <TitleScreen.h>

#include <SFML/Graphics.hpp>

SpaceInvaders::SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration)
    : _screenManager(configuration), _configuration(configuration), _logger("SpaceInvaders", configuration.LogLevel),
      _window(window)
{
    _logger.Debug("Game initialized");

    /** Initialize Game Screens */
    _screenManager.AddScreen<TitleScreen>(*this);
    _screenManager.SetCurrentScreen<TitleScreen>();
    _screenManager.Activate();
}

void SpaceInvaders::Run()
{
    _logger.Debug("Game started");

    sf::Clock clock;
    TimeTicker timeTicker;

    while (_window.isOpen())
    {
        const sf::Time frameTime = clock.restart();
        timeTicker.Accumulator += frameTime;
        timeTicker.ElapsedTime += frameTime;

        HandleEvents();

        while (timeTicker.Accumulator >= timeTicker.TimeStep)
        {
            timeTicker.Delta = timeTicker.Accumulator - timeTicker.TimeStep;
            Update(timeTicker);
            timeTicker.Accumulator -= timeTicker.TimeStep;
        }

        Render();
    }
}

sf::RenderWindow& SpaceInvaders::GetWindow() const
{
    return _window;
}

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

/**
 * TODO: delegate to each screen
 */
void SpaceInvaders::HandleEvents()
{
    _window.handleEvents([this](const sf::Event::Closed& event) { this->OnClose(event); },
                         [this](const sf::Event::KeyPressed& event) { this->OnKeyPressed(event); });

    _gameState.MousePos = sf::Mouse::getPosition(_window);
}

void SpaceInvaders::OnClose(const sf::Event::Closed&)
{
    /** We shut down the screen to unload the resources */
    _screenManager.CleanUp();
    _resourceManager.CleanUp();
    _window.close();
}

void SpaceInvaders::OnKeyPressed(const sf::Event::KeyPressed& keyPressed) const
{
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
        _window.close();
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
