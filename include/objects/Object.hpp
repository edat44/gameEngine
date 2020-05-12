//
// Created by edat44 on 5/11/20.
//

#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <containers/List.hpp>

namespace game {

class Object {
public:
    Object() : mActive(false) {}


    void Activate() { this->mActive = true; };
    void Deactivate() { this->mActive = false; }
    [[nodiscard]] bool Active() const { return this->mActive; }

private:
    bool mActive;
};

} // ns game


#endif //GAME_OBJECT_HPP
