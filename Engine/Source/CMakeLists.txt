add_subdirectory(Core)
add_subdirectory(Utilities)

add_library(Engine INTERFACE)
target_link_libraries(Engine INTERFACE Core Utilities)