add_library(SpaceInvaders
        Private/SpaceInvaders.cpp)
target_include_directories(SpaceInvaders PUBLIC
        Public
)
target_link_libraries(SpaceInvaders PRIVATE
        Core
        Screens
        Utils
        SFML::Graphics
)
