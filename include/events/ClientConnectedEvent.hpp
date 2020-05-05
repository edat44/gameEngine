//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_CLIENTCONNECTEDEVENT_HPP
#define GAME_CLIENTCONNECTEDEVENT_HPP

#include <SFML/Network/TcpSocket.hpp>
#include "Event.hpp"

class ClientConnectedEvent : public Event {
public:
    explicit ClientConnectedEvent(sf::TcpSocket *socket) : Event("ClientConnectedEvent"),
            socket(socket) {}

    void Handle() override;
private:
    sf::TcpSocket* socket;
};


#endif //GAME_CLIENTCONNECTEDEVENT_HPP
