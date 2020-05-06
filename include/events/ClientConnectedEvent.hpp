//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_CLIENTCONNECTEDEVENT_HPP
#define GAME_CLIENTCONNECTEDEVENT_HPP

#include <SFML/Network/TcpSocket.hpp>
#include <memory>
#include <events/Event.hpp>

namespace game::events {

class ClientConnectedEvent : public Event {
public:
    explicit ClientConnectedEvent(std::shared_ptr<sf::TcpSocket> socket) :
            Event("ClientConnectedEvent"), socket(std::move(socket)) {}

    void Handle() override;

private:
    std::shared_ptr<sf::TcpSocket> socket;
};

} // ns game::events


#endif //GAME_CLIENTCONNECTEDEVENT_HPP
