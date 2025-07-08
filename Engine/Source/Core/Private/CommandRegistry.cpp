// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "CommandRegistry.h"

CommandRegistry::CommandRegistry(const Configuration& configuration)
    : _configuration(configuration)
	, _nextCommandId(0)
{
}

int CommandRegistry::Register(std::shared_ptr<Command> command)
{
	const int commandId = _nextCommandId++;
	_commands[commandId] = std::move(command);
	return commandId;
}

void CommandRegistry::Execute(const int commandId)
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
