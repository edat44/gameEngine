#include <iostream>

#include <network/Server.hpp>


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    sf::TcpSocket socket;
    if (socket.connect(sf::IpAddress::getLocalAddress(), atoi(argv[1])) != sf::Socket::Done) {
        std::cout << "Could not connect!" << std::endl;
        return 1;
    }
    std::cout << socket.getRemoteAddress() << ":" << socket.getRemotePort() << "(" << socket.getLocalPort() << ")" << std::endl;
    std::string message;
    while (std::cin >> message) {
        sf::Packet p;
        p << message;
        socket.send(p);
//        std::cout << "Waiting for message..." << std::endl;
//        sf::Packet packet;
//        if (socket.receive(packet) != sf::Socket::Done) {
//            std::cout << "Reading error!" << std::endl;
//            return 2;
//        } else {
//            std::string receivedMessage;
//            packet >> receivedMessage;
//            std::cout << receivedMessage << std::endl;
//        }
    }
    socket.disconnect();
    return 0;
}
