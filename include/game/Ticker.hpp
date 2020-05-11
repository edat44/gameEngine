//
// Created by edat44 on 5/6/20.
//

#ifndef GAME_TICKER_HPP
#define GAME_TICKER_HPP


#include <SFML/System/Time.hpp>

namespace game {

class Ticker {
public:
    Ticker() : active(false) {};
    virtual void Tick(sf::Time dt) = 0;
    bool SetActive(bool isActive) { return this->active = isActive; };
    bool GetActive() { return this->active; }


protected:
    bool active;
};

} // ns game


#endif //GAME_TICKER_HPP
