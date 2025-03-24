// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Screen.h"

#include <Configuration.h>
#include <Logger.h>
#include <TimeTicker.h>
#include <typeindex>
#include <unordered_map>

class ScreenManager {
public:
    explicit ScreenManager(const Configuration& configuration);
    ~ScreenManager() = default;

    template <typename T, typename... Args>
    void AddScreen(Args&&... args)
    {
        _logger.Debug("Adding screen: " + std::string(typeid(T).name()));

        static_assert(std::is_base_of_v<Screen, T>, "T must be a subclass of Screen");

        std::type_index typeIndex(typeid(T));
        if (_screens.contains(typeIndex))
        {
            throw std::runtime_error("Screen already exists");
        }

        _screens.emplace(typeIndex, std::make_unique<T>(std::forward<Args>(args)...));

        if (_currentScreen == nullptr)
        {
            _currentScreen = _screens[typeIndex].get();
        }
    }

    template <typename T>
    void SetCurrentScreen()
    {
        _logger.Debug("Setting current screen: " + std::string(typeid(T).name()));

        std::type_index typeIndex(typeid(T));
        if (!_screens.contains(typeIndex))
        {
            throw std::runtime_error("Screen does not exist");
        }

        _currentScreen = _screens[typeIndex].get();
    }

    void CleanUp();

    void Activate() const;
    void Shutdown() const;
    void Update(const TimeTicker& timeTicker) const;
    void Render() const;
    void HandleEvents();

private:
    const Logger _logger;
    const Configuration& _configuration;
    std::pmr::unordered_map<std::type_index, std::unique_ptr<Screen>> _screens;
    Screen* _currentScreen;
};

#endif
