// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "Commands/PlayCommand.h"
#include "GameScreen/GameScreen.h"

void PlayCommand::Execute()
{
    LOG_DEBUG("Executing PlayCommand");
    _game.ScheduleCommand([&]()
    {
        _game.GetEngineContext().GetScreenManager().SetCurrentScreen(typeid(GameScreen));
    });
}
