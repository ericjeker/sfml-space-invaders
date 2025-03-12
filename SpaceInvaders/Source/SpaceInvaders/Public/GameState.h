// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/System/Vector2.hpp>

struct GameState
{
public:
    sf::Vector2i MousePos = sf::Vector2i(-1, -1);
    bool IsPaused = false;
    float Score = 0;
};


#endif
