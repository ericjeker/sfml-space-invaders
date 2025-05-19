set(CORE_SOURCES
        Private/ResourceManager.cpp
        Private/Screen.cpp
        Private/ScreenManager.cpp
        Private/Managers/GUIManager.cpp
        Private/Managers/ParticleConstellationManager.cpp
        Private/CommandRegistry.cpp
        Private/EventBus.cpp
        Private/Game.cpp
        Private/Game.cpp)

set(CORE_HEADERS
        # Collections are SoA, data-only structures, for holding states
        Public/Collections/ParticleCollection.h
        Public/Collections/GUI/ButtonCollection.h
        Public/Collections/GUI/TextCollection.h
        Public/Managers/GUIManager.h
        Public/Managers/ParticleConstellationManager.h
        Public/CommandRegistry.h
        Public/Command.h
        Public/EventBus.h
        Public/Game.h
        Public/GameState.h)

add_library(Core ${CORE_SOURCES} ${CORE_HEADERS})

target_include_directories(Core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Private
)

target_link_libraries(Core
        PRIVATE
        Utilities
        SFML::Graphics
)
