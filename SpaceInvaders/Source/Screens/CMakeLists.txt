add_library(Screens Private/GameScreen.cpp)
target_include_directories(Screens PUBLIC Public)
target_link_libraries(Screens PRIVATE
        Core
        SpaceInvaders
        Utils
        SFML::Graphics
)