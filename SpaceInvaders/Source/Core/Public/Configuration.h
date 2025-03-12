// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Logger.h"

#include <SFML/System/Vector2.hpp>

/**
* Simple configuration structure for the game.
*/
struct Configuration
{
    const sf::Vector2u WindowSize = {1920, 1080};
    const LogLevel LogLevel = LogLevel::Debug;
};

#endif
