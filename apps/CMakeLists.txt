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
TARGET_LINK_LIBRARIES(stack game_lib)

add_executable(queue queue.cpp)
TARGET_LINK_LIBRARIES(queue game_lib)

add_executable(game game.cpp)
target_link_libraries(game game_lib -lsfml-network -lsfml-system -lsfml-graphics
        -lsfml-window -lpthread)