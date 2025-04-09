// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef PLAYCOMMAND_H
#define PLAYCOMMAND_H

#include "Command.h"


class PlayCommand final : public Command {
public:
    explicit PlayCommand(SpaceInvaders& game) : Command(game) {}
    void Execute() override;
};


#endif
