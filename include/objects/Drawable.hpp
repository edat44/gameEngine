//
// Created by edat44 on 5/11/20.
//

#ifndef GAME_DRAWABLE_HPP
#define GAME_DRAWABLE_HPP

#include <objects/Object.hpp>
#include <SFML/System/Time.hpp>

namespace game {

class Drawable : public Object {
public:

    Drawable() : Object() {}

    virtual void Draw(sf::Time dt) = 0;
};

} // ns game

#endif //GAME_DRAWABLE_HPP
