// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/System/Vector2.hpp>

struct GameState
{
public:
    sf::Vector2f mousePos = sf::Vector2f(-1.f, -1.f);
    bool isPaused = false;
    float score = 0;
};


#endif
