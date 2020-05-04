//
// Created by edat44 on 5/4/20.
//

#include <network/Server.hpp>
#include <iostream>

Server::Server(int localPort) {
    this->listener = std::make_unique<sf::TcpListener>();
    if (this->listener->listen(localPort) != sf::Socket::Done) {
        std::cout << "Could not listen!" << std::endl;
    }
    this->selector.add(*this->listener);
    std::cout << "Listening on " << listener->getLocalPort() << std::endl;
    this->running = false;
}

void Server::Start() {
    this->running = true;
    this->listenThread = std::thread(&Server::Listen, this);
    std::cout << "Thread info: " <<
                 "id=" << this->listenThread.get_id() <<
                 "joinable=" << this->listenThread.joinable() << std::endl;
}

void Server::Listen() {
    std::cout << "Listening for socket data" << std::endl;
    while (this->running) {
        std::cout << "About to wait" << std::endl;
        if (this->selector.wait()) {
            std::cout << "Something is ready" << std::endl;
            if (selector.isReady(*this->listener)) {
                std::cout << "New connection incoming" << std::endl;
                auto socket = new sf::TcpSocket();
                if (this->listener->accept(*socket) == sf::Socket::Done) {
                    std::cout << "New connection ready!" << std::endl;
                    this->AddClient(socket);
                    sf::Packet p;
                    p << "Hello from the server!\n";
                    socket->send(p);
                } else {
                    std::cout << "Cannot create new connection" << std::endl;
                }
            } else {
                for (auto it = this->clients.begin(); it != this->clients.end();) {
                    auto socket = (*it)->getSocket();
                    if (this->selector.isReady(*socket)) {
                        std::cout << "Received new message from " << socket
                        ->getRemoteAddress() << std::endl;
                        sf::Packet packet;
                        switch(auto status = socket->receive(packet)) {
                        case sf::Socket::Done: {
                            std::cout << "New packet ready!" << std::endl;
                            std::string message;
                            packet >> message;
                            std::cout << "Message: " << message;
                            ++it;
                            break;
                        } case sf::Socket::Disconnected:
                            std::cout << "Socket to " << socket->getRemoteAddress() <<
                            " disconnected" << std::endl;
                            it = this->clients.erase(it);
                            this->selector.remove(*socket);
                            break;
                        default:
                            std::cout << "Unhandled packet status: " << status << std::endl;
                            break;
                        }
                    }
                }
            }
        } else {
            //std::cout << "Server timeout!" << std::endl;
        }
    }
}

void Server::AddClient(sf::TcpSocket *socket) {
    auto client = new Client(socket);
    this->clients.push_back(client);
    this->selector.add(*client->getSocket());
    std::cout << "New client created! total size: " << this->clients.size() << std::endl;
}
