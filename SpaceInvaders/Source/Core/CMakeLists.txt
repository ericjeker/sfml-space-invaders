set(LIBRARIES
        Private/ResourceManager.cpp
        Private/Screen.cpp
        Private/ScreenManager.cpp
        Private/Managers/GUIManager.cpp
        Private/Managers/ParticleConstellationManager.cpp
        Private/CommandRegistry.cpp
        Public/CommandRegistry.h)

set(HEADERS
        # Collections are SoA, data-only structures, for holding states
        Public/Collections/ParticleCollection.h
        Public/Collections/GUI/ButtonCollection.h
        Public/Collections/GUI/TextCollection.h
        Public/Command.h)

add_library(Core ${LIBRARIES} ${HEADERS})

target_include_directories(Core PUBLIC
        Public
        Public/Collections
        Public/Collections/GUI
        Public/Managers
        Public/Systems)

target_link_libraries(Core PRIVATE
        SpaceInvaders
        Utils
        SFML::Graphics)
