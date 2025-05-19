set(UTILS_SOURCES
        Private/Logger.cpp)
set(UTILS_HEADERS
        Public/Logger.h
        Public/TimeTicker.h)

# Create the library
add_library(Utilities ${UTILS_SOURCES} ${UTILS_HEADERS})

# Include dependencies in the library
target_include_directories(Utilities
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Private
)
