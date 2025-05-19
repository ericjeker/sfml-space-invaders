set(SPACEINVADERS_SOURCES
        Private/SpaceInvaders.cpp
        Private/GameScreen/GameScreen.cpp
        Private/TitleScreen/TitleScreen.cpp
        Private/Commands/PlayCommand.cpp
        Private/Commands/ExitCommand.cpp
        Private/GameScreen/Systems/BulletSystem.cpp
        Private/GameScreen/Systems/PlayerController.cpp)

set(SPACEINVADERS_HEADERS
        Public/GameScreen/Entities/Player.h
        Public/GameScreen/Collections/BulletCollection.h
        Public/GameScreen/Collections/EnemyCollection.h
        Public/GameScreen/Systems/BulletSystem.h
        Public/GameScreen/Systems/PlayerController.h)

add_library(SpaceInvaders
        ${SPACEINVADERS_SOURCES}
        ${SPACEINVADERS_HEADERS})

target_include_directories(SpaceInvaders
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Private
)

target_link_libraries(SpaceInvaders
        PUBLIC
        Core
        Utilities
        PRIVATE
        SFML::Graphics
        SFML::Window
)
