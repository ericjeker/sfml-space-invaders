// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

#include "Configuration.h"

#include "Managers/ResourceManager.h"
#include "Managers/ScreenManager.h"

#include <memory>

#include "SFML/Graphics/RenderWindow.hpp"


class EngineContext
{
public:
	EngineContext() = default;
	explicit EngineContext(Configuration configuration);
	~EngineContext() = default;

	Configuration& GetConfiguration() const;
	// EventSystem& GetEventSystem() const;
	// FileManager& GetFileManager() const;
	sf::RenderWindow& GetWindow() const;
	ResourceManager& GetResourceManager() const;
	ScreenManager& GetScreenManager() const;
	// SoundManager& GetSoundManager() const;

	void SetConfiguration(std::unique_ptr<Configuration> configuration);
	// void SetEventSystem(std::unique_ptr<EventSystem> eventSystem);
	// void SetFileManager(std::unique_ptr<FileManager> fileManager);
	void SetResourceManager(std::unique_ptr<ResourceManager> resourceManager);
	void SetScreenManager(std::unique_ptr<ScreenManager> screenManager);
	// void SetSoundManager(std::unique_ptr<SoundManager> soundManager);
	void SetWindow(std::unique_ptr<sf::RenderWindow> window);

private:
	std::unique_ptr<Configuration> _configuration;
	// std::unique_ptr<EventSystem> _eventSystem;
	// std::unique_ptr<FileManager> _fileManager;
	std::unique_ptr<ResourceManager> _resourceManager;
	std::unique_ptr<ScreenManager> _screenManager;
	// std::unique_ptr<SoundManager> _soundManager;
	std::unique_ptr<sf::RenderWindow> _window;
};

#endif // ENGINECONTEXT_H