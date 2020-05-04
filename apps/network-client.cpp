#include <iostream>

#include <network/Server.hpp>


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    sf::TcpSocket socket;
    if (socket.connect(sf::IpAddress::getLocalAddress(), 9003) != sf::Socket::Done) {
        std::cout << "Could not connect!";
    }
    std::cout << socket.getRemoteAddress() << ":" << socket.getRemotePort() << "(" << socket
    .getLocalPort() << ")" << std::endl;
    sf::Packet p;
    p << "Hello from client!\n";
    socket.send(p);
    std::cout << "Waiting for message..." << std::endl;
    sf::Packet packet;
    if (socket.receive(packet) != sf::Socket::Done) {
        std::cout << "Reading error!" << std::endl;
    } else {
        std::string message;
        packet >> message;
        std::cout << message << std::endl;
    }
    socket.disconnect();
    return 0;
}
