set(PRIVATE_SOURCES
        Private/SpaceInvaders.cpp
        Private/GameScreen/GameScreen.cpp
        Private/TitleScreen/TitleScreen.cpp
        Private/Commands/PlayCommand.cpp
        Public/Commands/PlayCommand.h
        Private/Commands/ExitCommand.cpp
        Public/Commands/ExitCommand.h)

add_library(SpaceInvaders
        ${PRIVATE_SOURCES})

target_include_directories(SpaceInvaders PUBLIC
        Public
        Public/GameScreen
        Public/TitleScreen
)
target_link_libraries(SpaceInvaders PRIVATE
        Core
        Utils
        SFML::Graphics
)
