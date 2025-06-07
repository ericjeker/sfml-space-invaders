// Copyright (c) Eric Jeker. All Rights Reserved.

#pragma once
#ifndef RESUMECOMMAND_H
#define RESUMECOMMAND_H

#include "Command.h"
#include "SpaceInvaders.h"


class ResumeCommand final : public Command
{
public:
	explicit ResumeCommand(SpaceInvaders& game)
		: Command(game)
	{
	}
	void Execute() override;
};


#endif // RESUMECOMMAND_H
