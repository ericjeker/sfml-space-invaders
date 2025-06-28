// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Logger.h"

#include "../Screen.h"

#include <SFML/Window/Event.hpp>

#include <functional>
#include <typeindex>
#include <unordered_map>

struct Configuration;

using ScreenFactory = std::function<std::unique_ptr<Screen>()>;

class ScreenManager
{
public:
    explicit ScreenManager(const Configuration& configuration);
    ~ScreenManager() = default;

    void RegisterScreen(const std::type_index& type, ScreenFactory factory);
    void SetCurrentScreen(const std::type_index& type);

    void CleanUp();

    // Methods below are delegated to the currently displayed screen
    void Activate() const;
    void Shutdown() const;
    void Update(const sf::Time& deltaTime) const;
    void Render() const;
    void HandleEvents(const std::optional<sf::Event>& event) const;

private:
    const Logger _logger;
    const Configuration& _configuration;
    std::unordered_map<std::type_index, ScreenFactory> _screens;
    std::unique_ptr<Screen> _currentScreen = nullptr;
};

#endif
