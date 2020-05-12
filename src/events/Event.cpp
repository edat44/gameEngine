//
// Created by edat44 on 5/5/20.
//

#include <events/Event.hpp>

namespace game::events {

std::string Event::GetType() const {
    return this->mType;
}

} // ns game::events