// Copyright (c) Eric Jeker. All Rights Reserved.

#include "ResumeCommand.h"

#include "GameScreen/GameScreen.h"

void ResumeCommand::Execute()
{
	_logger.Debug("Executing PlayCommand");
	_game.ScheduleCommand([&]()
	{
		_game.GetEngineContext().GetScreenManager().SetCurrentScreen(typeid(GameScreen));
	});
}
