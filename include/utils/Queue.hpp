//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_QUEUE_HPP
#define GAME_QUEUE_HPP

#include <utils/Node.hpp>
#include <optional>

template <typename T>
class Queue {
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}
    ~Queue();

    [[nodiscard]] bool empty() const;
    void enqueue(T element);
    std::optional<T> dequeue();

    void print(std::ostream& out=std::cout) const;

    friend std::ostream& operator<<(std::ostream &out, const Queue &q) {
        out << "size: " << q.size << std::endl;
        if (q.empty()) {
            std::cout << "<empty>";
        } else {
            for (Node<T>* curr = q.head; curr; curr = curr->next) {
                std::cout << curr->data;
                if (curr->next) {
                    std::cout << ", ";
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
};

template <typename T>
Queue<T>::~Queue() {
    Node<T>* curr = this->head;
    Node<T>* next = curr;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

template <typename T>
bool Queue<T>::empty() const {
    return this->size == 0;
}

template <typename T>
void Queue<T>::enqueue(T element) {
    auto node = new Node(element);
    if (this->empty()) {
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
std::optional<T> Queue<T>::dequeue() {
    if (this->empty()) {
        return std::optional<T>();
    } else {
        T data = this->head->data;
        Node<T>* newHead = this->head->next;
        delete this->head;
        this->size--;
        if (this->empty()) {
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
void Queue<T>::print(std::ostream& out) const {
    out << *this;
}

#endif //GAME_QUEUE_HPP
