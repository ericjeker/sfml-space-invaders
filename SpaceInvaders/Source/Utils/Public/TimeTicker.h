// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TIMETICKER_H
#define TIMETICKER_H

#include <SFML/System/Time.hpp>

struct TimeTicker
{
    sf::Time delta = sf::Time::Zero;
    sf::Time accumulator = sf::Time::Zero;
    const sf::Time timeStep = sf::seconds(1.0f / 60.0f);
    sf::Time elapsedTime = sf::Time::Zero;
};

#endif
