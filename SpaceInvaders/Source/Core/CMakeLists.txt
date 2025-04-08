set(LIBRARIES
        Private/ResourceManager.cpp
        Private/Screen.cpp
        Private/ScreenManager.cpp
        Private/Managers/GUIManager.cpp
        Private/Systems/ParticleSystem.cpp)

set(HEADERS
        Public/Containers/GUI/ButtonCollection.h
        Public/Containers/GUI/TextCollection.h
        Public/Containers/ParticleCollection.h)

add_library(Core ${LIBRARIES} ${HEADERS})

target_include_directories(Core PUBLIC
        Public
        Public/Containers
        Public/Containers/GUI
        Public/Managers
        Public/Systems)

target_link_libraries(Core PRIVATE
        SpaceInvaders
        Utils
        SFML::Graphics)
