// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include "Game.h"
#include "Logger.h"

class Command
{
public:
    explicit Command(Game& game)
        : _logger("Command", game.GetConfiguration().LogLevel)
        , _game(game)
    {
    }
    virtual ~Command() = default;
    virtual void Execute() = 0;

protected:
    Logger _logger;
    Game& _game;
};


#endif
