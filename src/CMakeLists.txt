# Generate list of all headers, and make sure they are 'tracked' by the IDE
FILE(GLOB_RECURSE HEADER_LIST "${CMAKE_SOURCE_DIR}/include/*.h")
source_group(TREE ${PROJECT_SOURCE_DIR}/include PREFIX "Header Files" FILES ${HEADER_LIST})

message("Headers: ${HEADER_LIST}")

add_library(cow_library
        window.cpp ${HEADER_LIST})

target_include_directories(cow_library PUBLIC ../include)