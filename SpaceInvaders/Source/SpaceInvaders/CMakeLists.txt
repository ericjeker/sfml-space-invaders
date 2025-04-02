file(GLOB_RECURSE PRIVATE_SOURCES CONFIGURE_DEPENDS "Private/*.cpp")
add_library(SpaceInvaders
        ${PRIVATE_SOURCES}
        Public/GameScreen/Entities/Bullet.h
        Public/GameScreen/Entities/Enemy.h
)

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
