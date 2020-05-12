# CMake structure inspired by https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Game
        VERSION 0.1
        DESCRIPTION "A game written in c++"
        LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 17)


include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

add_subdirectory(apps)


# Doxygen script from: https://vicrucann.github.io/tutorials/quick-cmake-doxygen/
# Create an option to build documentation and turn it on by default
option(BUILD_DOC "Build documentation" ON)

# Check if doxygen is installed
#find_package(Doxygen)
#if (DOXYGEN_FOUND)
#    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
#    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#
#    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#    message("Doxygen build started")
#
#    message("Doxygen exec: ${DOXYGEN_EXECUTABLE}, out: ${DOXYGEN_OUT}")
#
#    add_custom_target(doc_doxygen ALL
#            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#            COMMENT "Generating API documentation with Doxygen")
#
#else (DOXYGEN_FOUND)
#    message("Doxygen need to be installed to generate the doxygen documentation")
#endif (DOXYGEN_FOUND)

