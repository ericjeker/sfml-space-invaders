add_library(Core
        Private/ResourceManager.cpp
        Private/ScreenManager.cpp
        Private/Screen.cpp
        Public/GUI/Clickable.h
        Private/GUI/Clickable.cpp
        Private/GUI/Component.cpp
        Public/GUI/Component.h
        Private/GUI/Button.cpp
        Public/GUI/Button.h
        Public/ResourceLoader.h)
target_include_directories(Core PUBLIC
        Public)
target_link_libraries(Core PRIVATE
        Utils
        SFML::Graphics)