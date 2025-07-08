set(SPACEINVADERS_SOURCES
        Commands/ExitCommand.cpp
        Commands/PauseCommand.cpp
        Commands/PlayCommand.cpp
        Commands/QuitCommand.cpp
        Commands/ResumeCommand.cpp
        GameScreen/GameScreen.cpp
        GameScreen/Systems/BulletSpawnerSystem.cpp
        GameScreen/Systems/BulletSystem.cpp
        GameScreen/Systems/EnemySystem.cpp
        GameScreen/Systems/PlayerController.cpp
        PauseScreen/PauseScreen.cpp
        TitleScreen/TitleScreen.cpp

        Main.cpp
        SpaceInvaders.cpp
)

# Library
add_library(SpaceInvadersLibrary)
target_sources(SpaceInvadersLibrary
        PRIVATE
        ${SPACEINVADERS_SOURCES}
)
target_include_directories(SpaceInvadersLibrary
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(SpaceInvadersLibrary
        PRIVATE
        Vendor
        Engine
)

# Executable
add_executable(SpaceInvaders)
target_sources(SpaceInvaders
        PRIVATE
        ${SPACEINVADERS_SOURCES}
)

# Linking everything
target_link_libraries(SpaceInvaders
        PRIVATE
        Vendor
        Engine
        SpaceInvadersLibrary
)

