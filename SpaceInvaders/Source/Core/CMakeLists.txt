add_library(Core INTERFACE)
target_include_directories(Core INTERFACE
        Public
)
target_link_libraries(Core INTERFACE
        Utils
        SFML::Graphics)