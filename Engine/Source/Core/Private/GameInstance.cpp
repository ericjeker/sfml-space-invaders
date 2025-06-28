// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "GameInstance.h"

GameInstance::GameInstance(std::unique_ptr<EngineContext> engineContext)
	: _engineContext(std::move(engineContext))
{
}
EngineContext& GameInstance::GetEngineContext() const
{
	return *_engineContext;
};

void GameInstance::ScheduleCommand(const std::function<void()>& command)
{
    _deferredCommands.push(command);
};

void GameInstance::ExecuteDeferredCommands()
{
    while (!_deferredCommands.empty())
    {
        _deferredCommands.front()();
        _deferredCommands.pop();
    }
};
