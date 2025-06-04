set(UTILITIES_SOURCES
        Private/Logger.cpp
)

add_library(Utilities)
#add_library(Engine::Utilities ALIAS Utilities)

target_sources(Utilities PRIVATE ${UTILITIES_SOURCES})
target_include_directories(Utilities PUBLIC Public)