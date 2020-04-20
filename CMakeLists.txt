# CMake structure inspired by https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(CowGame
        VERSION 0.1
        DESCRIPTION "A remake of the original cowgame"
        LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 17)

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)

add_subdirectory(apps)