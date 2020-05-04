add_subdirectory(utils)
add_subdirectory(game)
add_subdirectory(network)

# Generate list of all headers, and make sure they are 'tracked' by the IDE
FILE(GLOB_RECURSE HEADER_LIST "${CMAKE_SOURCE_DIR}/include/**.hpp")
source_group(TREE ${CMAKE_SOURCE_DIR}/include FILES ${HEADER_LIST})

message("Headers: ${HEADER_LIST}")