// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ScreenManager.h"

#include <Configuration.h>
#include <TimeTicker.h>

ScreenManager::ScreenManager(const Configuration& configuration) : _configuration(configuration), _currentScreen(nullptr), _logger("ScreenManager", LogLevel::Info) {}

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

void ScreenManager::Update(const TimeTicker& timeTicker) const
{
    if (_currentScreen != nullptr)
    {
        _currentScreen->Update(timeTicker);
    }
}

void ScreenManager::Render() const
{
    if (_currentScreen != nullptr)
    {
        _currentScreen->Render();
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
