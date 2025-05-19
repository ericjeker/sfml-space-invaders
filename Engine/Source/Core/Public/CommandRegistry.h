// Copyright (c) 2025 Eric Jeker. All rights reserved.

#pragma once
#ifndef COMMANDREGISTRY_H
#define COMMANDREGISTRY_H

#include "Command.h"


#include <Configuration.h>
#include <Logger.h>
#include <memory>
#include <unordered_map>


class CommandRegistry
{
public:
    explicit CommandRegistry(const Configuration& configuration);
    ~CommandRegistry() = default;
    void Register(int commandId, std::shared_ptr<Command> command);
    void Execute(int commandId);
    void Clear();

private:
    Configuration _configuration;
    Logger _logger;

    std::unordered_map<int, std::shared_ptr<Command>> _commands;
};


#endif
