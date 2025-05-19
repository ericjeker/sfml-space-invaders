// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ScreenManager.h"
#include "TimeTicker.h"

ScreenManager::ScreenManager(const Configuration& configuration)
    : _logger("ScreenManager", LogLevel::Info), _configuration(configuration), _currentScreen(nullptr)
{
}

void ScreenManager::CleanUp()
{
    // For each screen, we call the shutdown method
    for (auto& [_, screen] : _screens)
    {
        screen->Shutdown();
    }

    _screens.clear();
    _currentScreen = nullptr;
}

void ScreenManager::Update(const sf::Time& deltaTime) const
{
    if (_currentScreen != nullptr)
    {
        _currentScreen->Update(deltaTime);
    }
}

void ScreenManager::Render() const
{
    if (_currentScreen != nullptr)
    {
        _currentScreen->Render();
    }
}

void ScreenManager::HandleEvents(const std::optional<sf::Event>& event) const
{
    if (_currentScreen != nullptr)
    {
        _currentScreen->HandleEvents(event);
    }
}

void ScreenManager::Activate() const
{
    if (_currentScreen != nullptr)
    {
        _currentScreen->Activate();
    }
}

void ScreenManager::Shutdown() const
{
    if (_currentScreen != nullptr)
    {
        _currentScreen->Shutdown();
    }
}
