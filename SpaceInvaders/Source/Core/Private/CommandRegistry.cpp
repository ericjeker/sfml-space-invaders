// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "CommandRegistry.h"

CommandRegistry::CommandRegistry(const Configuration& configuration)
    : _configuration(configuration), _logger("CommandRegistry", configuration.LogLevel)
{
}

void CommandRegistry::Register(const int commandId, std::shared_ptr<Command> command)
{
    _commands[commandId] = std::move(command);
}

void CommandRegistry::Execute(const int commandId)
{
    if (auto it = _commands.find(commandId); it != _commands.end())
    {
        it->second->Execute();
    }
}

void CommandRegistry::Clear()
{
    _commands.clear();
}
