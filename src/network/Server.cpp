//
// Created by edat44 on 5/4/20.
//

#include <network/Server.hpp>
#include <iostream>
#include <events/ClientConnectedEvent.hpp>
#include <events/ClientMessageEvent.hpp>
#include <events/ClientDisconnectedEvent.hpp>

namespace game::network {

Server::Server(int localPort, std::shared_ptr<game::Engine> engine) {
    this->listener = std::make_unique<sf::TcpListener>();
    if (this->listener->listen(localPort) != sf::Socket::Done) {
        std::cout << "Could not listen!" << std::endl;
    }
    this->listener->setBlocking(false);
    std::cout << "Listening on " << listener->getLocalPort() << std::endl;
    this->engine = std::move(engine);
    this->engine->AddTicker(this);
}


void Server::Tick(sf::Time dt) {
    std::cout << "Checking for network data" << std::endl;
    {
        auto socket = std::make_shared<sf::TcpSocket>();
        switch (auto status = this->listener->accept(*socket)) {
            case sf::Socket::Done: {
                auto client = this->AddClient(socket);
                this->engine->AddEvent(std::make_shared<events::ClientConnectedEvent>(client));
                break;
            } case sf::Socket::NotReady:
                break;
            default:
                std::cout << "Unhandled listen socket status: " << status << std::endl;
                break;
        }
    }
    std::cout << "Looping through clients..." << std::endl;
    for (auto& it = this->clients.begin(); it != this->clients.end();) {
        std::cout << "Found a client!" << std::endl;
        auto& client = it->data;
        auto packet = std::make_shared<sf::Packet>();
        switch(auto status = client->GetSocket()->receive(*packet)) {
        case sf::Socket::Done: {
            this->engine->AddEvent(std::make_shared<events::ClientMessageEvent>(client,packet));
            it++;
            break;
        } case sf::Socket::Disconnected:
            it = this->clients.erase(it);
            this->engine->AddEvent(std::make_shared<events::ClientDisconnectedEvent>(client));
            break;
        default:
            std::cout << "Unhandled packet status: " << status << std::endl;
            it++;
            break;
        }
    }
    std::cout << "Done looping" << std::endl;
}

std::shared_ptr<Client> Server::AddClient(const std::shared_ptr<sf::TcpSocket>& socket) {
    socket->setBlocking(false);
    auto client = std::make_shared<Client>(socket);
    this->clients.Insert(client);
    std::cout << "New client created! total size: " << this->clients.Size() << std::endl;
    return client;
}

} // ns game::network
