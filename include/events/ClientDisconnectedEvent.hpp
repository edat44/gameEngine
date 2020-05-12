//
// Created by edat44 on 5/6/20.
//

#ifndef GAME_CLIENTDISCONNECTEDEVENT_HPP
#define GAME_CLIENTDISCONNECTEDEVENT_HPP

#include <events/Event.hpp>
#include <memory>
#include <network/Client.hpp>

namespace game::events {

class ClientDisconnectedEvent: public Event {
public:
    explicit ClientDisconnectedEvent(std::shared_ptr<game::network::Client> client) :
            Event("ClientDisconnectedEvent"), mClient(std::move(client)) {}

    void Handle() override;
private:
    std::shared_ptr<game::network::Client> mClient;
};

} // ns game::events


#endif //GAME_CLIENTDISCONNECTEDEVENT_HPP
