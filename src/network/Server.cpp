//
// Created by edat44 on 5/4/20.
//

#include <network/Server.hpp>
#include <iostream>
#include <events/ClientConnectedEvent.hpp>
#include <events/ClientMessageEvent.hpp>
#include <events/ClientDisconnectedEvent.hpp>

Server::Server(int localPort, eventQueue_t events) {
    this->listener = std::make_unique<sf::TcpListener>();
    if (this->listener->listen(localPort) != sf::Socket::Done) {
        std::cout << "Could not listen!" << std::endl;
    }
    this->selector.add(*this->listener);
    std::cout << "Listening on " << listener->getLocalPort() << std::endl;
    this->running = false;
    this->events = std::move(events);
}

void Server::Start() {
    this->running = true;
    this->listenThread = std::thread(&Server::Listen, this);
    this->listenThread.detach();
}

void Server::Stop() {
    this->running = false;
}

void Server::Listen() {
    std::cout << "Listening for socket data to server" << std::endl;
    while (this->running) {
        if (this->selector.wait()) {
            if (selector.isReady(*this->listener)) {
                auto socket = std::make_shared<sf::TcpSocket>();
                if (this->listener->accept(*socket) == sf::Socket::Done) {
                    this->AddClient(socket);
                    this->events->Enqueue(std::make_shared<ClientConnectedEvent>(socket));
                } else {
                    std::cout << "Cannot create new connection" << std::endl;
                }
            } else {
                for (auto it = this->clients.begin(); it != this->clients.end();) {
                    auto socket = (*it)->GetSocket();
                    if (this->selector.isReady(*socket)) {
                        auto packet = std::make_shared<sf::Packet>();
                        switch(auto status = socket->receive(*packet)) {
                        case sf::Socket::Done: {
                            this->events->Enqueue(std::make_shared<ClientMessageEvent>(socket,
                                    packet));
                            it++;
                            break;
                        } case sf::Socket::Disconnected:
                            it = this->clients.erase(it);
                            this->selector.remove(*socket);
                            this->events->Enqueue(std::make_shared<ClientDisconnectedEvent>
                                    (socket));
                            break;
                        default:
                            std::cout << "Unhandled packet status: " << status << std::endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Server shutting down!" << std::endl;
}

void Server::AddClient(const std::shared_ptr<sf::TcpSocket>& socket) {
    auto client = std::make_shared<Client>(socket);
    this->clients.push_back(client);
    this->selector.add(*client->GetSocket());
    std::cout << "New client created! total size: " << this->clients.size() << std::endl;
}
