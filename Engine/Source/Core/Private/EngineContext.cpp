// Copyright (c) Eric Jeker. All Rights Reserved.

#include "EngineContext.h"

#include "Configuration.h"

EngineContext::EngineContext(Configuration configuration)
	: _configuration(std::make_unique<Configuration>(std::move(configuration)))
{
}

Configuration& EngineContext::GetConfiguration() const
{
	return *_configuration;
}

FileManager& EngineContext::GetFileManager() const
{
	return *_fileManager;
}

sf::RenderWindow& EngineContext::GetWindow() const
{
	return *_window;
}

ResourceManager& EngineContext::GetResourceManager() const
{
	return *_resourceManager;
}
ScreenManager& EngineContext::GetScreenManager() const
{
	return *_screenManager;
}

void EngineContext::SetConfiguration(std::unique_ptr<Configuration> configuration)
{
	_configuration = std::move(configuration);
}

void EngineContext::SetFileManager(std::unique_ptr<FileManager> fileManager)
{
	_fileManager = std::move(fileManager);
}

void EngineContext::SetResourceManager(std::unique_ptr<ResourceManager> resourceManager)
{
	_resourceManager = std::move(resourceManager);
}

void EngineContext::SetScreenManager(std::unique_ptr<ScreenManager> screenManager)
{
	_screenManager = std::move(screenManager);
}

void EngineContext::SetWindow(std::unique_ptr<sf::RenderWindow> window)
{
	_window = std::move(window);
}
