// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "CommandRegistry.h"

int CommandRegistry::Register(std::shared_ptr<Command> command)
{
	const int commandId = _nextCommandId++;
	_commands[commandId] = std::move(command);
	return commandId;
}

void CommandRegistry::Execute(const int commandId) const
{
	if (_commands.contains(commandId))
	{
		_commands.at(commandId)->Execute();
	}
}

void CommandRegistry::Clear()
{
    _commands.clear();
}
