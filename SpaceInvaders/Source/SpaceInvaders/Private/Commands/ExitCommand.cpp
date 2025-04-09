// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Commands/ExitCommand.h"

void ExitCommand::Execute()
{
    _logger.Debug("Executing ExitCommand");
    _game.Exit();
}
