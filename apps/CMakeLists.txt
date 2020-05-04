add_executable(graphics graphics.cpp)

TARGET_LINK_LIBRARIES(graphics
        game_lib

        -lsfml-graphics
        -lsfml-window
        -lsfml-system
        -lsfml-audio
        -lsfml-network)

add_executable(network-host network-host.cpp)

TARGET_LINK_LIBRARIES(network-host
        game_lib

        -lsfml-graphics
        -lsfml-window
        -lsfml-system
        -lsfml-audio
        -lsfml-network
        -lpthread)

add_executable(network-client network-client.cpp)

TARGET_LINK_LIBRARIES(network-client
        game_lib

        -lsfml-graphics
        -lsfml-window
        -lsfml-system
        -lsfml-audio
        -lsfml-network
        -lpthread)

add_executable(stack stack.cpp)

TARGET_LINK_LIBRARIES(stack
        game_lib)