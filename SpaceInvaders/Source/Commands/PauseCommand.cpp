// Copyright (c) Eric Jeker. All Rights Reserved.

#include "PauseCommand.h"

#include "PauseScreen/PauseScreen.h"

void PauseCommand::Execute()
{
	_logger.Debug("Executing PauseCommand");
	_game.ScheduleCommand([&]()
	{
		_game.GetEngineContext().GetScreenManager().SetCurrentScreen(typeid(PauseScreen));
	});
}
