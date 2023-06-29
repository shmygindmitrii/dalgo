# dalgo

set( DALGO_HEADERS 
     inc/dkmp.h 
)

set( DALGO_SOURCES
    src/dkmp.cpp
)

add_library( Dalgo
    STATIC
    ${DALGO_SOURCES}
    ${DALGO_HEADERS}
)

target_link_libraries( Dalgo
)

target_include_directories( Dalgo 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_definitions( Dalgo PUBLIC VERBOSE_OUTPUT )
