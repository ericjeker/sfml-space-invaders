# Add the Source directory. This will build our library and executable.
add_subdirectory(Source)

# --- Testing Setup ---
# Option to enable/disable building tests.
option(BUILD_TESTING "Build the tests" ON)

if(BUILD_TESTING)
    # Add the Tests directory.
    add_subdirectory(Tests)
endif()