// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

#include "Configuration.h"

#include "Managers/FileManager.h"
#include "Managers/ResourceManager.h"
#include "Managers/ScreenManager.h"

#include <memory>

#include "SFML/Graphics/RenderWindow.hpp"

/**
 * @class EngineContext
 *
 * @brief Represents the core context of the engine that facilitates
 *        managing essential states, configurations, and resources for
 *        the engine's operation.
 *
 * The EngineContext class is designed to store and provide access
 * to engine-level resources and configurations needed for runtime
 * execution. It acts as a central hub for managing the dependencies
 * and state of different subsystems within the engine. Subsystems or
 * components can query the context to retrieve shared data or services.
 *
 * Responsibilities:
 * - Manage shared resources and states required by subsystems.
 * - Provide interfaces for accessing configurations and utilities.
 * - Serve as a communication layer between engine components.
 *
 * Thread-safety and resource management policies depend on the
 * implementation details and usage of this class. Refer to the
 * implementation or detailed documentation for thread access rules.
 *
 * Common Use:
 * The class is typically instantiated as a single instance and
 * shared across the engine components as a dependency injection
 * mechanism.
 */
class EngineContext
{
public:
	EngineContext() = default;
	explicit EngineContext(Configuration configuration);
	~EngineContext() = default;

	[[nodiscard]] Configuration& GetConfiguration() const;
	// EventSystem& GetEventSystem() const;
	[[nodiscard]] FileManager& GetFileManager() const;
	[[nodiscard]] ResourceManager& GetResourceManager() const;
	[[nodiscard]] ScreenManager& GetScreenManager() const;
	// SoundManager& GetSoundManager() const;
	[[nodiscard]] sf::RenderWindow& GetWindow() const;

	void SetConfiguration(std::unique_ptr<Configuration> configuration);
	// void SetEventSystem(std::unique_ptr<EventSystem> eventSystem);
	void SetFileManager(std::unique_ptr<FileManager> fileManager);
	void SetResourceManager(std::unique_ptr<ResourceManager> resourceManager);
	void SetScreenManager(std::unique_ptr<ScreenManager> screenManager);
	// void SetSoundManager(std::unique_ptr<SoundManager> soundManager);
	void SetWindow(std::unique_ptr<sf::RenderWindow> window);

private:
	std::unique_ptr<Configuration> _configuration;
	// std::unique_ptr<EventSystem> _eventSystem;
	std::unique_ptr<FileManager> _fileManager;
	std::unique_ptr<ResourceManager> _resourceManager;
	std::unique_ptr<ScreenManager> _screenManager;
	// std::unique_ptr<SoundManager> _soundManager;
	std::unique_ptr<sf::RenderWindow> _window;
};

#endif // ENGINECONTEXT_H