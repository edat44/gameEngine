//
// Created by edat44 on 5/6/20.
//

#ifndef GAME_TICKABLE_HPP
#define GAME_TICKABLE_HPP


#include <objects/Object.hpp>
#include <SFML/System/Time.hpp>

namespace game {

class Tickable : public Object {
public:

    Tickable() : Object() {}
    virtual void Tick(sf::Time dt) = 0;
};

} // ns game


#endif //GAME_TICKABLE_HPP
