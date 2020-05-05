//
// Created by edat44 on 5/4/20.
//

#ifndef GAME_SERVER_HPP
#define GAME_SERVER_HPP

#include <SFML/Network.hpp>
#include <thread>
#include <list>

#include <memory>
#include "Client.hpp"
#include <utils/Queue.hpp>

class Server {
public:
    explicit Server(int localPort, eventQueue_t events);

    void Start();
    void Stop();

private:
    void Listen();
    void AddClient(sf::TcpSocket *socket);

    sf::SocketSelector selector;
    std::unique_ptr<sf::TcpListener> listener;
    std::list<Client*> clients;
    std::thread listenThread;
    bool running;
    eventQueue_t events;
};


#endif //GAME_SERVER_HPP
