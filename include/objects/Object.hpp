//
// Created by edat44 on 5/11/20.
//

#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <containers/List.hpp>

namespace game {

class Object {
public:
    Object() : active(false) {}


    void Activate() { this->active = true; };
    void Deactivate() { this->active = false; }
    [[nodiscard]] bool GetActive() const { return this->active; }

private:
    bool active;
};

} // ns game


#endif //GAME_OBJECT_HPP
