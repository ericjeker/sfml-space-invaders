// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "Command.h"


class ExitCommand final : public Command {
public:
    explicit ExitCommand(SpaceInvaders& game) : Command(game) {}
    void Execute() override;
};


#endif
