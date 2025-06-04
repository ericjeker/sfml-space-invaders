set(CORE_SOURCES
        Private/CommandRegistry.cpp
        Private/EventBus.cpp
        Private/Game.cpp
        Private/Screen.cpp
        Private/Managers/GUIManager.cpp
        Private/Managers/ParticleConstellationManager.cpp
        Private/Managers/ResourceManager.cpp
        Private/Managers/ScreenManager.cpp
)

add_library(Core)
# add_library(Engine::Core ALIAS Core)

target_sources(Core PRIVATE ${CORE_SOURCES})
target_include_directories(Core PUBLIC Public)

target_link_libraries(Core PRIVATE Utilities SFML::Window SFML::Graphics)
