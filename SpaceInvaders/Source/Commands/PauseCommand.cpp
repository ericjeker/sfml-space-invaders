// Copyright (c) Eric Jeker. All Rights Reserved.

#include "PauseCommand.h"

#include "PauseScreen/PauseScreen.h"

PauseCommand::PauseCommand(SpaceInvaders& game)
	: Command(game)
{
}

void PauseCommand::Execute()
{
	LOG_DEBUG("Executing PauseCommand");
	_game.ScheduleCommand([&]() { _game.GetEngineContext().GetScreenManager().SetCurrentScreen(typeid(PauseScreen)); });
}
