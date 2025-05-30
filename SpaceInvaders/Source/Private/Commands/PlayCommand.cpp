// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Commands/PlayCommand.h"
#include "GameScreen/GameScreen.h"

void PlayCommand::Execute()
{
    _logger.Debug("Executing PlayCommand");
    _game.ScheduleCommand([&]()
    {
        _game.GetScreenManager().SetCurrentScreen(typeid(GameScreen));
    });
}
