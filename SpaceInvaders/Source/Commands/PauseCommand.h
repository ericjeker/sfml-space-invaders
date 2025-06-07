// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef PAUSECOMMAND_H
#define PAUSECOMMAND_H

#include "Command.h"
#include "SpaceInvaders.h"


class PauseCommand final : public Command
{
public:
	explicit PauseCommand(SpaceInvaders& game)
		: Command(game)
	{
	}
	void Execute() override;
};


#endif // PAUSECOMMAND_H
