// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Commands/ExitCommand.h"

void ExitCommand::Execute()
{
    LOG_DEBUG("Executing ExitCommand");
    _game.ScheduleCommand([&]()
    {
        _game.Exit();
    });
}
