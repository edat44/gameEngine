//
// Created by edat44 on 5/6/20.
//

#ifndef GAME_CLIENTDISCONNECTEDEVENT_HPP
#define GAME_CLIENTDISCONNECTEDEVENT_HPP

#include <events/Event.hpp>
#include <memory>
#include <SFML/Network/TcpSocket.hpp>


class ClientDisconnectedEvent: public Event {
public:
    explicit ClientDisconnectedEvent(std::shared_ptr<sf::TcpSocket> socket) :
    Event("ClientDisconnectedEvent"), socket(std::move(socket)) {}

    void Handle() override;
private:
    std::shared_ptr<sf::TcpSocket> socket;
};


#endif //GAME_CLIENTDISCONNECTEDEVENT_HPP
