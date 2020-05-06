//
// Created by edat44 on 5/6/20.
//

#ifndef GAME_CLIENTMESSAGEEVENT_HPP
#define GAME_CLIENTMESSAGEEVENT_HPP


#include <memory>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>
#include <utility>
#include <events/Event.hpp>

namespace game::events {

class ClientMessageEvent : public Event {
public:
    ClientMessageEvent(std::shared_ptr<sf::TcpSocket> socket,
            std::shared_ptr<sf::Packet> packet) :
            Event("ClientMessageEvent"), socket(std::move(socket)), packet(std::move(packet)) {}

    void Handle() override;
private:
    std::shared_ptr<sf::TcpSocket> socket;
    std::shared_ptr<sf::Packet> packet;
};

} // ns game::events


#endif //GAME_CLIENTMESSAGEEVENT_HPP