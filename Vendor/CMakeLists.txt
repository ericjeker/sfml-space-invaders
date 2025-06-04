add_subdirectory(SFML)

add_library(Vendor INTERFACE)
target_link_libraries(Vendor INTERFACE
        SFML::Graphics
        SFML::Window
        SFML::System
)