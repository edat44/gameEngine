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

template <typename T>
class Queue {
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}
    ~Queue();

    [[nodiscard]] bool Empty() const;
    void Enqueue(T element);
    std::optional<T> Dequeue();

    void Print(std::ostream& out= std::cout) const;

    friend std::ostream& operator<<(std::ostream &out, const Queue &q) {
        out << "size: " << q.size << std::endl;
        if (q.Empty()) {
            out << "<Empty>";
        } else {
            for (Node<T>* curr = q.head; curr; curr = curr->next) {
                out << curr->data;
                if (curr->next) {
                   out << ", ";
                }
            }
        }
        out << std::endl;
        return out;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
    std::mutex lock;
};

template <typename T>
Queue<T>::~Queue() {
    std::lock_guard<std::mutex> l(this->lock);
    Node<T>* curr = this->head;
    Node<T>* next = curr;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

template <typename T>
bool Queue<T>::Empty() const {
    return this->size == 0;
}

template <typename T>
void Queue<T>::Enqueue(T element) {
    std::lock_guard<std::mutex> l(this->lock);
    auto node = new Node(element);
    if (this->Empty()) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        node->prev = this->tail;
        this->tail = node;
    }
    this->size++;
}

template <typename T>
std::optional<T> Queue<T>::Dequeue() {
    std::lock_guard<std::mutex> l(this->lock);
    if (this->Empty()) {
        return std::optional<T>();
    } else {
        T data = this->head->data;
        Node<T>* newHead = this->head->next;
        delete this->head;
        this->size--;
        if (this->Empty()) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->head = newHead;
            this->head->prev = nullptr;
        }
        return data;
    }
}

template <typename T>
void Queue<T>::Print(std::ostream& out) const {
    std::lock_guard<std::mutex> l(this->lock);
    out << *this;
}

using eventQueue_t = std::shared_ptr<Queue<Event*>>;

#endif //GAME_QUEUE_HPP
