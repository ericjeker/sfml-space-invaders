set(CORE_SOURCES
        Private/CommandRegistry.cpp
        Private/EngineContext.cpp
        Private/EventBus.cpp
        Private/GameInstance.cpp
        Private/Screen.cpp
        Private/UI/Button.cpp
        Private/UI/RoundedRectangleShape.cpp
        Private/UI/Text.cpp
        Private/UI/UIManager.cpp
        Private/UI/UIComponent.cpp
        Private/Managers/ParticleConstellationManager.cpp
        Private/Managers/FileManager.cpp
        Private/Managers/ResourceManager.cpp
        Private/Managers/ScreenManager.cpp
)

add_library(Core)
# add_library(Engine::Core ALIAS Core)

target_sources(Core PRIVATE ${CORE_SOURCES})
target_include_directories(Core PUBLIC Public)

target_link_libraries(Core PRIVATE Vendor Utilities SFML::Window SFML::Graphics)
