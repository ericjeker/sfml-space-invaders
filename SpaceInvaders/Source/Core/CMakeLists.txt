add_library(Core
        Private/ResourceManager.cpp
        Private/ScreenManager.cpp
        Private/Screen.cpp
        Public/Entity.h
        Public/System.h
        Private/GUI/Text.cpp
        Private/Systems/TextRenderer.cpp)

target_include_directories(Core PUBLIC
        Public
        Public/GUI
        Public/Systems)

target_link_libraries(Core PRIVATE
        SpaceInvaders
        Utils
        SFML::Graphics)
