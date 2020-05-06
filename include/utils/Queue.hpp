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

template <typename T>
class Queue : public LinkedList<T> {
public:
    Queue() : LinkedList<T>() {}
    void Enqueue(T element);
    std::optional<T> Dequeue();
};

template <typename T>
void Queue<T>::Enqueue(T element) {
    this->PushBack(element);
}

template <typename T>
std::optional<T> Queue<T>::Dequeue() {
    return this->PopFront();
}

using event_t = std::variant<Event, sf::Event>;
using eventQueue_t = std::shared_ptr<Queue<std::shared_ptr<Event>>>;

#endif //GAME_QUEUE_HPP
