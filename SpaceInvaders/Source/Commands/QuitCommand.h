// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef QUITCOMMAND_H
#define QUITCOMMAND_H

#include "Command.h"

#include "SpaceInvaders.h"

class QuitCommand final : public Command
{
public:
	explicit QuitCommand(SpaceInvaders& game)
		: Command(game)
	{
	}
	void Execute() override;
};


#endif // QUITCOMMAND_H
