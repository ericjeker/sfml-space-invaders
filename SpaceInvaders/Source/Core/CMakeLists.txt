add_library(Core Private/ResourceManager.cpp)
target_include_directories(Core PUBLIC Public)
target_link_libraries(Core PRIVATE
        Utils
        SFML::Graphics)