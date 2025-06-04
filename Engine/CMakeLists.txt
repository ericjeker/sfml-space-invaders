# Process the nested sub-directories
add_subdirectory(Source/Core)
add_subdirectory(Source/Utilities)

add_library(Engine INTERFACE)
target_link_libraries(Engine INTERFACE Core Utilities)