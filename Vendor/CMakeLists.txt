include(FetchContent)

# SFML
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# nlohmann::json
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)
FetchContent_MakeAvailable(json)

# Virtual library grouping together the dependencies above
add_library(Vendor INTERFACE)

# Link all dependencies to the Vendor library
target_link_libraries(Vendor INTERFACE
        SFML::Graphics
        SFML::Window
        SFML::System
        nlohmann_json::nlohmann_json
)