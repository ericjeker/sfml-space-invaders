add_library(Core
        Private/ResourceManager.cpp
        Private/ScreenManager.cpp
        Private/Screen.cpp)
target_include_directories(Core PUBLIC
        Public
        Public/GUI)
target_link_libraries(Core PRIVATE
        Utils
        SFML::Graphics)