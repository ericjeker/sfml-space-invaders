set(SPACEINVADERS_HEADERS
        Source
)

set(SPACEINVADERS_SOURCES
        Source/Commands/ExitCommand.cpp
        Source/Commands/PauseCommand.cpp
        Source/Commands/PlayCommand.cpp
        Source/Commands/QuitCommand.cpp
        Source/Commands/ResumeCommand.cpp
        Source/GameScreen/GameScreen.cpp
        Source/GameScreen/Systems/BulletSystem.cpp
        Source/GameScreen/Systems/PlayerController.cpp
        Source/PauseScreen/PauseScreen.cpp
        Source/SpaceInvaders.cpp
        Source/TitleScreen/TitleScreen.cpp
)

# Executable
add_executable(SpaceInvaders Source/Main.cpp)
target_sources(SpaceInvaders PRIVATE
        ${SPACEINVADERS_HEADERS}
        ${SPACEINVADERS_SOURCES}
)

target_include_directories(SpaceInvaders PRIVATE Source)

target_link_libraries(SpaceInvaders
        PRIVATE
        Vendor
        Engine
)

