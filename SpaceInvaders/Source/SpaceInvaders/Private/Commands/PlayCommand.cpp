// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Commands/PlayCommand.h"

#include <GameScreen.h>

void PlayCommand::Execute()
{
    _logger.Debug("Executing PlayCommand");
    _game.GetScreenManager().SetCurrentScreen<GameScreen>();
}
