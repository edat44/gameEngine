//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_LINKEDLIST_HPP
#define GAME_LINKEDLIST_HPP

#include <containers/Node.hpp>
#include <optional>
#include <iostream>
#include <mutex>
#include <memory>
#include <events/Event.hpp>
#include <functional>

namespace game::containers {

template <typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList();

    [[nodiscard]] bool Empty() const;

    void Print(std::ostream& out= std::cout) const;

    friend std::ostream& operator<<(std::ostream &out, const LinkedList &list) {
        std::lock_guard<std::mutex> l(list.lock);
        out << "size: " << list.size << std::endl;
        if (list.Empty()) {
            out << "<Empty>";
        } else {
            for (Node<T>* curr = list.head; curr; curr = curr->next) {
                out << curr->data;
                if (curr->next) {
                    out << ", ";
                }
            }
        }
        out << std::endl;
        return out;
    }

    [[nodiscard]] size_t Size() const;



protected:
    void PushBack(T element);
    void PushFront(T element);
    void Push(T element, Node<T>* &front, Node<T>* &back,
              std::function<Node<T>**(Node<T>*)> next, std::function<Node<T>**(Node<T>*)> prev);

    std::optional<T> PopFront();
    std::optional<T> PopBack();
    std::optional<T> Pop(Node<T>* &front, Node<T>* &back,
            std::function<Node<T>**(Node<T>*)> next, std::function<Node<T>**(Node<T>*)> prev);

    Node<T>* head;
    Node<T>* tail;
    size_t size;

private:
    std::mutex lock;
};

template <typename T>
LinkedList<T>::~LinkedList() {
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
bool LinkedList<T>::Empty() const {
    return this->size == 0;
}

template <typename T>
size_t LinkedList<T>::Size() const {
    return this->size;
}

template <typename T>
void LinkedList<T>::PushFront(T element) {
    this->Push(element, this->head, this->tail, &Node<T>::Next, &Node<T>::Prev);
}

template <typename T>
void LinkedList<T>::PushBack(T element) {
    return this->Push(element, this->tail, this->head, &Node<T>::Prev, &Node<T>::Next);
}

template <typename T>
void LinkedList<T>::Push(T element, Node<T>* &front, Node<T>* &back,
                         std::function<Node<T>**(Node<T>*)> next,
                         std::function<Node<T>**(Node<T>*)> prev) {
    std::lock_guard<std::mutex> l(this->lock);
    auto node = new Node(element);
    if (this->Empty()) {
        front = node;
        back = node;
    } else {
        *prev(front) = node;
        *next(node) = front;
        front = node;
    }
    this->size++;
}

template <typename T>
std::optional<T> LinkedList<T>::PopFront() {
    return this->Pop(this->head, this->tail, &Node<T>::Next, &Node<T>::Prev);
}

template <typename T>
std::optional<T> LinkedList<T>::PopBack() {
    return this->Pop(this->tail, this->head, &Node<T>::Prev, &Node<T>::Next);
}

template<typename T>
std::optional<T> LinkedList<T>::Pop(Node<T>* &front, Node<T>* &back,
        std::function<Node<T>**(Node<T>*)> next, std::function<Node<T>**(Node<T>*)> prev) {
    std::lock_guard<std::mutex> l(this->lock);
    if (this->Empty()) {
        return std::optional<T>();
    } else {
        T data = front->data;
        Node<T>* newHead = *next(front);
        delete front;
        this->size--;
        if (this->Empty()) {
            front = nullptr;
            back = nullptr;
        } else {
            front = newHead;
            *prev(front) = nullptr;
        }
        return data;
    }
}

template <typename T>
void LinkedList<T>::Print(std::ostream& out) const {
    out << *this;
}

} // ns game::containers

#endif //GAME_LINKEDLIST_HPP
