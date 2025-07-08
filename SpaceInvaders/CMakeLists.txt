# Add the Source directory. This will build our library and executable.
add_subdirectory(Source)

# --- Testing Setup ---
# Option to enable/disable building tests.
option(BUILD_TESTING "Build the tests" OFF)

if (BUILD_TESTING)
    # Enable testing for the project
    enable_testing()

    # Add the Tests directory.
    add_subdirectory(Tests)
endif ()