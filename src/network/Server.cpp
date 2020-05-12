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
    this->mListener = std::make_unique<sf::TcpListener>();
    if (this->mListener->listen(localPort) != sf::Socket::Done) {
        std::cout << "Could not listen!" << std::endl;
    }
    this->mListener->setBlocking(false);
    std::cout << "Listening on " << mListener->getLocalPort() << std::endl;
    this->mEngine = std::move(engine);
    this->mEngine->AddTickable(this);
}

Server::~Server() {
    this->mListener->close();
    for (auto& client : this->mClients) {
        client->GetSocket()->disconnect();
    }
}

void Server::Tick(sf::Time dt) {
    std::cout << "Checking for network data" << std::endl;
    {
        auto socket = std::make_shared<sf::TcpSocket>();
        switch (auto status = this->mListener->accept(*socket)) {
            case sf::Socket::Done: {
                auto client = this->AddClient(socket);
                this->mEngine->AddEvent(std::make_shared<events::ClientConnectedEvent>(client));
                break;
            } case sf::Socket::NotReady:
                break;
            default:
                std::cout << "Unhandled listen socket status: " << status << std::endl;
                break;
        }
    }
    std::cout << "# clients connected: " << this->mClients.Size() << std::endl;
    for (auto it = this->mClients.begin(); it != this->mClients.end();) {
        auto& client = *it;
        std::cout << "Checking client " << client->GetSocket()->getRemoteAddress() << " for data!" << std::endl;
        auto status = sf::Socket::Done;
        while (status == sf::Socket::Done) {
            auto packet = std::make_shared<sf::Packet>();
            switch (status = client->GetSocket()->receive(*packet)) {
                case sf::Socket::Done: {
                    this->mEngine->AddEvent(std::make_shared<events::ClientMessageEvent>(client, packet));
                    break;
                }
                case sf::Socket::Disconnected:
                    it = this->mClients.erase(it);
                    this->mEngine->AddEvent(std::make_shared<events::ClientDisconnectedEvent>(client));
                    break;
                default:
                    std::cout << "Not ready!" << std::endl;
                    it++;
                    break;
            }
        }
    }
}

std::shared_ptr<Client> Server::AddClient(const std::shared_ptr<sf::TcpSocket>& socket) {
    socket->setBlocking(false);
    auto client = std::make_shared<Client>(socket);
    this->mClients.Insert(client);
    std::cout << "New client created! total size: " << this->mClients.Size() << std::endl;
    return client;
}

} // ns game::network
