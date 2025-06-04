set(SPACEINVADERS_SOURCES
        Source/SpaceInvaders.cpp
        Source/GameScreen/GameScreen.cpp
        Source/TitleScreen/TitleScreen.cpp
        Source/Commands/PlayCommand.cpp
        Source/Commands/ExitCommand.cpp
        Source/GameScreen/Systems/BulletSystem.cpp
        Source/GameScreen/Systems/PlayerController.cpp
)

set(SPACEINVADERS_HEADERS
        Source/GameScreen/Entities/Player.h
        Source/GameScreen/Collections/BulletCollection.h
        Source/GameScreen/Collections/EnemyCollection.h
        Source/GameScreen/Systems/BulletSystem.h
        Source/GameScreen/Systems/PlayerController.h
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

