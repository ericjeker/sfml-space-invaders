// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include <Logger.h>
#include <SpaceInvaders.h>


class SpaceInvaders;
class Command
{
public:
    explicit Command(SpaceInvaders& game) : _logger("Command", game.GetConfiguration().LogLevel), _game(game) {}
    virtual ~Command() = default;
    virtual void Execute() = 0;

protected:
    Logger _logger;
    SpaceInvaders& _game;
};


#endif
