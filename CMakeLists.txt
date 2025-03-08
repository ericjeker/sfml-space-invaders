cmake_minimum_required(VERSION 3.30)

if(NOT DEFINED VCPKG_TARGET_TRIPLET)
    set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "Default triplet")
endif()

project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML COMPONENTS Graphics Window CONFIG REQUIRED)

add_subdirectory(src/core)
add_subdirectory(src/game)
add_subdirectory(src/utils)

# Executable
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE
        core
        game
        utils
        SFML::Graphics
        SFML::Window)