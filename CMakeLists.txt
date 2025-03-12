cmake_minimum_required(VERSION 3.30)

if(NOT DEFINED VCPKG_TARGET_TRIPLET)
    set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "Default triplet")
endif()

project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML COMPONENTS Graphics Window CONFIG REQUIRED)

add_subdirectory(SpaceInvaders/Source/Core)
add_subdirectory(SpaceInvaders/Source/Screens)
add_subdirectory(SpaceInvaders/Source/SpaceInvaders)
add_subdirectory(SpaceInvaders/Source/Utils)

# Executable
add_executable(Main SpaceInvaders/Source/Main.cpp)
target_link_libraries(Main PRIVATE
        Core
        Screens
        SpaceInvaders
        Utils
        SFML::Graphics
        SFML::Window)