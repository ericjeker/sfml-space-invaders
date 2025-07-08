// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef COMMANDREGISTRY_H
#define COMMANDREGISTRY_H

#include "Command.h"


#include <Configuration.h>
#include <Logger.h>
#include <memory>
#include <unordered_map>

/**
 * @class CommandRegistry
 * @brief A class that acts as a registry to manage and store commands.
 *
 * This class is responsible for registering, retrieving, and managing
 * command objects or handlers. It serves as a centralized storage to
 * facilitate communication and execution of commands in an application.
 * CommandRegistry ensures efficient lookup and organization of commands
 * using unique identifiers.
 *
 * Typical use cases include systems where command patterns are implemented,
 * or in applications requiring dynamic command execution and management.
 */
class CommandRegistry
{
public:
    explicit CommandRegistry(const Configuration& configuration);
    ~CommandRegistry() = default;

	int Register(std::shared_ptr<Command> command);
    void Execute(int commandId);
    void Clear();

private:
	// TODO: replace this with unique_ptr
    Configuration _configuration;

    // TODO: use std::type_index instead of int
	std::unordered_map<int, std::shared_ptr<Command>> _commands;
	int _nextCommandId;
};


#endif
