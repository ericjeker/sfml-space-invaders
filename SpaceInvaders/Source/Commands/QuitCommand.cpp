// Copyright (c) Eric Jeker. All Rights Reserved.

#include "QuitCommand.h"

#include "TitleScreen/TitleScreen.h"

void QuitCommand::Execute()
{
	LOG_DEBUG("Executing QuitCommand");
	_game.ScheduleCommand([&]()
	{
		_game.GetEngineContext().GetScreenManager().SetCurrentScreen(typeid(TitleScreen));
	});
}
