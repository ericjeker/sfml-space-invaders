// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef TIMETICKER_H
#define TIMETICKER_H

#include <SFML/System/Time.hpp>

struct TimeTicker
{
    sf::Time Delta = sf::Time::Zero;
    sf::Time Accumulator = sf::Time::Zero;
    const sf::Time TimeStep = sf::seconds(1.0f / 60.0f);
    sf::Time ElapsedTime = sf::Time::Zero;
};

#endif //TIMETICKER_H
