//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP


#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <utils/Queue.hpp>
#include <events/Event.hpp>

class Engine {
public:
    Engine() : running(false), tickTime(sf::seconds(1.0 / 1.0)),
               events(std::make_shared<Queue<std::shared_ptr<Event>>>()) {}

    void Run();

    void Stop();

    [[nodiscard]] eventQueue_t Events() const;

private:
    void Tick(sf::Time dt);

    bool running;
    sf::Time tickTime;
    eventQueue_t events;
    sf::Clock clock;
};


#endif //GAME_ENGINE_HPP
