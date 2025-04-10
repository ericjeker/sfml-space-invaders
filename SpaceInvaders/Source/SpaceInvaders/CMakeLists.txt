set(LIBRARIES
        Private/SpaceInvaders.cpp
        Private/GameScreen/GameScreen.cpp
        Private/TitleScreen/TitleScreen.cpp
        Private/Commands/PlayCommand.cpp
        Private/Commands/ExitCommand.cpp
        Private/GameScreen/Systems/PlayerController.cpp)

set(HEADERS
        Public/GameScreen/Entities/Player.h
        Public/GameScreen/Collections/BulletCollection.h
        Public/GameScreen/Collections/EnemyCollection.h
        Public/GameScreen/Systems/PlayerController.h)

add_library(SpaceInvaders
        ${LIBRARIES}
        ${HEADERS})

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
