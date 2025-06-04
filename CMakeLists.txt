cmake_minimum_required(VERSION 3.30)

project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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
