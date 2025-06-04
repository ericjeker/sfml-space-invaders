// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ScreenManager.h"
#include "TimeTicker.h"


ScreenManager::ScreenManager(const Configuration& configuration)
    : _logger("ScreenManager", LogLevel::Info)
    , _configuration(configuration)
{
}

void ScreenManager::RegisterScreen(const std::type_index& type, ScreenFactory factory)
{
    _logger.Debug("Registering screen: " + std::string(type.name()));
    _screens[type] = std::move(factory);
}

void ScreenManager::SetCurrentScreen(const std::type_index& type)
{
    _logger.Debug("Setting current screen: " + std::string(type.name()));

    if (!_screens.contains(type))
    {
        throw std::runtime_error("Screen was not registered");
    }

    // Shutting down the current screen if it exists
    if (_currentScreen != nullptr)
    {
        _currentScreen->Shutdown();
    }

    // Activating the new screen
    _currentScreen = _screens[type]();
    _currentScreen->Activate();
}

void ScreenManager::CleanUp()
{
    _screens.clear();
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
