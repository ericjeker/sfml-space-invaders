// Copyright (c) Eric Jeker. All Rights Reserved.

#include <SFML/Graphics.hpp>

#include "SpaceInvaders.h"
#include "Logger.h"
#include "TimeTicker.h"

SpaceInvaders::SpaceInvaders(sf::RenderWindow& window, const Configuration& configuration)
    : _Configuration(configuration), _Logger("SpaceInvaders", configuration.LogLevel), _Window(window),
      _GameScreen(*this)
{
    /** TODO: Initialize global resources */
    /** Activate GameScreen */
    _GameScreen.Activate();
}

SpaceInvaders::~SpaceInvaders() = default;

void SpaceInvaders::Run()
{
    _Logger.Info("Game started");

    sf::Clock clock;
    TimeTicker timeTicker;

    while (_Window.isOpen())
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
    return _Window;
}

GameState& SpaceInvaders::GetState()
{
    return _GameState;
}

const Configuration& SpaceInvaders::GetConfiguration() const
{
    return _Configuration;
}

ResourceManager& SpaceInvaders::GetResourceManager()
{
    return _ResourceManager;
}

void SpaceInvaders::HandleEvents()
{
    _Window.handleEvents(
        [this](const sf::Event::Closed& event)
        {
            this->OnClose(event);
        },
        [this](const sf::Event::KeyPressed& event)
        {
            this->OnKeyPressed(event);
        });

    _GameState.MousePos = sf::Mouse::getPosition(_Window);
}

void SpaceInvaders::OnClose(const sf::Event::Closed&)
{
    /** We shut down the screen to unload the resources */
    _GameScreen.Shutdown();
    _ResourceManager.ClearResources();
    _Window.close();
}

void SpaceInvaders::OnKeyPressed(const sf::Event::KeyPressed& keyPressed) const
{
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
        _Window.close();
}

void SpaceInvaders::Update(const TimeTicker& timeTicker)
{
    _GameScreen.Update(timeTicker);
}

void SpaceInvaders::Render() const
{
    _Window.clear();
    _GameScreen.Render();
    _Window.display();
}
