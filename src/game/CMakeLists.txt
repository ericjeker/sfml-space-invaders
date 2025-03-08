add_library(game
        src/Game.cpp
        src/screens/GameScreen.cpp)
target_include_directories(game PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/screens
)
target_link_libraries(game PRIVATE
        core
        utils
        SFML::Graphics
)
