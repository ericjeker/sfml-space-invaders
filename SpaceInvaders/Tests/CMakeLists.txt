# Fetch the GoogleTest framework from GitHub
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add a new executable for our tests
add_executable(SpaceInvadersTests)
target_sources(SpaceInvadersTests
        PRIVATE
        PlayerControllerTests.cpp
)

# Link our test executable against GoogleTest
# This automatically sets up the main() function and all necessary dependencies
target_link_libraries(SpaceInvadersTests
        PRIVATE
        gtest_main
        SFML::Graphics
        SpaceInvadersLibrary
)

# Add our test executable to CTest, which CLion uses to discover tests
include(GoogleTest)
gtest_discover_tests(SpaceInvadersTests)
