cmake_minimum_required(VERSION 3.30)

project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Platform-specific configurations
if (UNIX AND NOT APPLE)
    # Linux-specific settings
    find_package(PkgConfig REQUIRED)
    find_package(X11 REQUIRED)

    # Additional Linux libraries that might be needed
    find_package(Threads REQUIRED)
elseif (WIN32)
    # Windows-specific settings
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

# Add the Engine and Game source code
add_subdirectory(Engine)
add_subdirectory(Vendor)
add_subdirectory(SpaceInvaders)

# Copy the Assets folder
file(
        COPY
        ${CMAKE_SOURCE_DIR}/Assets
        DESTINATION
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
