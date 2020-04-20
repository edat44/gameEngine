add_executable(cows main.cpp)

TARGET_LINK_LIBRARIES(cows
        cow_library
        -lsfml-graphics
        -lsfml-window
        -lsfml-system
        -lsfml-audio
        -lsfml-network)