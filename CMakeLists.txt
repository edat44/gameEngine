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