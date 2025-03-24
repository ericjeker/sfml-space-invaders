file(GLOB_RECURSE PRIVATE_SOURCES CONFIGURE_DEPENDS "Private/*.cpp")
add_library(SpaceInvaders
        ${PRIVATE_SOURCES}
)

target_include_directories(SpaceInvaders PUBLIC
        Public
        Public/Screens
)
target_link_libraries(SpaceInvaders PRIVATE
        Core
        Utils
        SFML::Graphics
)
