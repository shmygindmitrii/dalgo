cmake_minimum_required(VERSION 3.24)

if (WIN32)
    set(CMAKE_GENERATOR_TOOLSET "v142" CACHE STRING "Platform Toolset" FORCE)
endif()

project(
    DAlgoWithSamples
    VERSION 0.01
    DESCRIPTION "Homebrew implementation of classical algorithms and solutions"
    LANGUAGES CXX
)

set( ORGANIZATION DmitriiHandsAndGiantsHeads )

if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_LIST_DIR} PROPERTY VS_STARTUP_PROJECT DAlgoWithSamples)
endif()

add_subdirectory( dalgo )
add_subdirectory( samples )

