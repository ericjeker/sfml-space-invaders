set(SPACEINVADERS_HEADERS
        Source/Commands/CommandId.h
        Source/Commands/ExitCommand.h
        Source/Commands/PauseCommand.h
        Source/Commands/PlayCommand.h
        Source/Commands/QuitCommand.h
        Source/Commands/ResumeCommand.h
        Source/GameScreen/Entities/PlayerState.h
        Source/GameScreen/Collections/BulletCollection.h
        Source/GameScreen/Collections/EnemyCollection.h
        Source/GameScreen/Systems/BulletSystem.h
        Source/GameScreen/Systems/PlayerController.h
        Source/PauseScreen/PauseScreen.h
        Source/TitleScreen/TitleScreen.h
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
add_executable(SpaceInvaders Source/Main.cpp
        Source/GameScreen/Systems/BulletSpawnerSystem.cpp
        Source/GameScreen/Systems/BulletSpawnerSystem.h
        Source/GameScreen/Renderers/BulletCollectionRenderer.cpp
        Source/GameScreen/Renderers/BulletCollectionRenderer.h)
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

