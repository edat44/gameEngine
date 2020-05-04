FILE(GLOB_RECURSE SOURCE_LIST "${CMAKE_SOURCE_DIR}/src/**.cpp")

# Generate list of all headers, and make sure they are 'tracked' by the IDE
FILE(GLOB_RECURSE HEADER_LIST "${CMAKE_SOURCE_DIR}/include/**.hpp")
source_group(TREE ${CMAKE_SOURCE_DIR}/include FILES ${HEADER_LIST})

message("Headers: ${HEADER_LIST}")

add_library(game_lib
        ${SOURCE_LIST}
        ${HEADER_LIST})