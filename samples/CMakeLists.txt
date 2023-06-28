set( SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set( DEPENDENCIES
    Dalgo
)

add_executable( DAlgoWithSamples ${SOURCES})

target_link_libraries( DAlgoWithSamples
    ${DEPENDENCIES}
)

