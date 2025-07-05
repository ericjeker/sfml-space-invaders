// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include "GameInstance.h"
#include "Logger.h"

class Command
{
public:
    explicit Command(GameInstance& game)
        : _logger("Command", game.GetEngineContext().GetConfiguration().CurrentLogLevel)
        , _game(game)
    {
    }
    virtual ~Command() = default;
    virtual void Execute() = 0;

protected:
    Logger _logger;
    GameInstance& _game;
};


#endif
