// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowEnums.hpp>

#include <string>

/**
 * Simple configuration structure for the game.
 */
namespace Configuration
{

constexpr std::string WindowTitle = "Space Invaders";
constexpr sf::Vector2u WindowSize = {1920, 1080};
constexpr auto WindowStyle = sf::Style::None;
constexpr auto WindowState = sf::State::Windowed;

constexpr unsigned int FramesPerSecond = 60;

constexpr bool IsVSync = true;
constexpr bool IsFullscreen = false;
constexpr unsigned int AntiAliasingLevel = 16;

};

#endif
