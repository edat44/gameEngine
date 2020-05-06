//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_QUEUE_HPP
#define GAME_QUEUE_HPP

#include <utils/Node.hpp>
#include <optional>
#include <iostream>
#include <mutex>
#include <memory>
#include <events/Event.hpp>
#include <utils/LinkedList.hpp>
#include <variant>
#include <SFML/Window/Event.hpp>

namespace game::utils {

template<typename T>
class Queue : public LinkedList<T> {
public:
    Queue() : LinkedList<T>() {}

    void Enqueue(T element);

    std::optional<T> Dequeue();
};

template<typename T>
void Queue<T>::Enqueue(T element) {
    this->PushBack(element);
}

template<typename T>
std::optional<T> Queue<T>::Dequeue() {
    return this->PopFront();
}

using event_t = std::variant<std::shared_ptr<events::Event>, std::shared_ptr<sf::Event>>;
using eventRawQueue_t = Queue<event_t>;
using eventQueue_t = std::shared_ptr<eventRawQueue_t>;

} // ns game::utils

#endif //GAME_QUEUE_HPP
