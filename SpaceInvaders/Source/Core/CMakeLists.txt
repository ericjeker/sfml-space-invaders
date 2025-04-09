set(LIBRARIES
        Private/ResourceManager.cpp
        Private/Screen.cpp
        Private/ScreenManager.cpp
        Private/Managers/GUIManager.cpp
        Private/Systems/ParticleSystem.cpp)

set(HEADERS
        # Collections are SoA, data-only structures, for holding states
        Public/Collections/ParticleCollection.h
        Public/Collections/GUI/ButtonCollection.h
        Public/Collections/GUI/TextCollection.h)

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
