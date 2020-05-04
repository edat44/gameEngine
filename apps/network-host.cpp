#include <cassert>
#include <cstddef>
#include <iostream>

#include <SFML/Graphics.hpp>

#include <utils/Window.hpp>
#include <network/Server.hpp>


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    Server server(9003);
    server.Start();
    std::cin.get();
    return 0;
}
