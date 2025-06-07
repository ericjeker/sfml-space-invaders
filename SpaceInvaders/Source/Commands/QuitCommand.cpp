// Copyright (c) Eric Jeker. All Rights Reserved.

#include "QuitCommand.h"

#include "TitleScreen/TitleScreen.h"

void QuitCommand::Execute()
{
	_logger.Debug("Executing QuitCommand");
	_game.ScheduleCommand([&]()
	{
		_game.GetScreenManager().SetCurrentScreen(typeid(TitleScreen));
	});
}
