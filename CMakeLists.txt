cmake_minimum_required(VERSION 3.30)

if (NOT DEFINED VCPKG_TARGET_TRIPLET)
    # Using dynamically linked libraries means they have to be in the system PATH
    set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "Default triplet")
endif ()

project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add SFML as a package
find_package(SFML COMPONENTS Graphics Window CONFIG REQUIRED)

# Add the Engine and Game source code
add_subdirectory(Engine/Source)
add_subdirectory(SpaceInvaders/Source)

# Executable
add_executable(Main SpaceInvaders/Source/Main.cpp)
target_link_libraries(Main
        PRIVATE
        Core
        Utilities
        SpaceInvaders
        SFML::Graphics
        SFML::Window
)

# Copy the Assets folder
file(
        COPY
        ${CMAKE_SOURCE_DIR}/SpaceInvaders/Assets
        DESTINATION
        ${CMAKE_BINARY_DIR}
)
