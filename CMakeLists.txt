cmake_minimum_required(VERSION 3.30)

if(NOT DEFINED VCPKG_TARGET_TRIPLET)
    # Using dynamically linked libraries means they have to be in the system PATH
    set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "Default triplet")
endif()

project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML COMPONENTS Graphics Window CONFIG REQUIRED)

add_subdirectory(SpaceInvaders/Source/Core)
add_subdirectory(SpaceInvaders/Source/SpaceInvaders)
add_subdirectory(SpaceInvaders/Source/Utils)

# Executable
add_executable(Main SpaceInvaders/Source/Main.cpp)
target_link_libraries(Main PRIVATE
        Core
        SpaceInvaders
        Utils
        SFML::Graphics
        SFML::Window)

# Copy the Assets folder
file(COPY
        ${CMAKE_SOURCE_DIR}/SpaceInvaders/Assets DESTINATION ${CMAKE_BINARY_DIR})

## Copy required DLLs after the build
#add_custom_command(TARGET Main POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        # Mingw DLLs:
#        "${MINGW_BIN_PATH}/libstdc++-6.dll"
#        "${MINGW_BIN_PATH}/libgcc_s_seh-1.dll"
#        "${MINGW_BIN_PATH}/libwinpthread-1.dll"
#        # SFML DLLs:
#        "${SFML_BIN_PATH}/sfml-graphics-2.dll"
#        "${SFML_BIN_PATH}/sfml-window-2.dll"
#        "${SFML_BIN_PATH}/sfml-system-2.dll"
#        # Other DLLs:
#        $<TARGET_FILE_DIR:Main>)

# Install target for Steam deployment
#install(TARGETS Main
#        RUNTIME DESTINATION .
#        RENAME SpaceInvaders.exe)

## Install dependencies (DLLs)
#install(FILES
#        "${MINGW_BIN_PATH}/libstdc++-6.dll"
#        "${MINGW_BIN_PATH}/libgcc_s_seh-1.dll"
#        "${MINGW_BIN_PATH}/libwinpthread-1.dll"
#        # SFML DLLs
#        "${SFML_PATH}/bin/sfml-graphics-2.dll"
#        "${SFML_PATH}/bin/sfml-window-2.dll"
#        "${SFML_PATH}/bin/sfml-system-2.dll"
#        DESTINATION lib)
#
## Install assets
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/SpaceInvaders/Assets
#        DESTINATION .)

