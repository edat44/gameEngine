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
    typedef Node<T> NodeType;
    typedef size_t SizeType;

    LinkedList() : mHead(nullptr), mTail(nullptr), mSize(0) {}
    ~LinkedList();

    [[nodiscard]] bool Empty() const;

    void Print(std::ostream& out= std::cout) const;

    friend std::ostream& operator<<(std::ostream &out, const LinkedList &list) {
        std::lock_guard<std::mutex> l(list.mLock);
        out << "size: " << list.mSize << std::endl;
        if (list.Empty()) {
            out << "<Empty>";
        } else {
            for (NodeType curr = list.mHead; curr; curr = curr->mNext) {
                out << curr->mData;
                if (curr->mNext) {
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
    void Push(T element, NodeType* &front, NodeType* &back,
              std::function<NodeType**(NodeType*)> next, std::function<NodeType**(NodeType*)> prev);

    std::optional<T> PopFront();
    std::optional<T> PopBack();
    std::optional<T> Pop(NodeType* &front, NodeType* &back,
            std::function<NodeType**(NodeType*)> next, std::function<NodeType**(NodeType*)> prev);

    NodeType* mHead;
    NodeType* mTail;
    SizeType mSize;

private:
    std::mutex mLock;
};

template <typename T>
LinkedList<T>::~LinkedList() {
    std::lock_guard<std::mutex> l(this->mLock);
    NodeType* curr = this->mHead;
    NodeType* next = curr;
    while (curr) {
        next = curr->mNext;
        delete curr;
        curr = next;
    }
}

template <typename T>
bool LinkedList<T>::Empty() const {
    return this->mSize == 0;
}

template <typename T>
size_t LinkedList<T>::Size() const {
    return this->mSize;
}

template <typename T>
void LinkedList<T>::PushFront(T element) {
    this->Push(element, this->mHead, this->mTail, &Node<T>::Next, &Node<T>::Prev);
}

template <typename T>
void LinkedList<T>::PushBack(T element) {
    return this->Push(element, this->mTail, this->mHead, &Node<T>::Prev, &Node<T>::Next);
}

template <typename T>
void LinkedList<T>::Push(T element, NodeType* &front, NodeType* &back,
                         std::function<NodeType**(NodeType*)> next,
                         std::function<NodeType**(NodeType*)> prev) {
    std::lock_guard<std::mutex> l(this->mLock);
    auto node = new Node(element);
    if (this->Empty()) {
        front = node;
        back = node;
    } else {
        *prev(front) = node;
        *next(node) = front;
        front = node;
    }
    this->mSize++;
}

template <typename T>
std::optional<T> LinkedList<T>::PopFront() {
    return this->Pop(this->mHead, this->mTail, &Node<T>::Next, &Node<T>::Prev);
}

template <typename T>
std::optional<T> LinkedList<T>::PopBack() {
    return this->Pop(this->mTail, this->mHead, &Node<T>::Prev, &Node<T>::Next);
}

template<typename T>
std::optional<T> LinkedList<T>::Pop(NodeType* &front, NodeType* &back,
        std::function<Node<T>**(NodeType*)> next, std::function<Node<T>**(NodeType*)> prev) {
    std::lock_guard<std::mutex> l(this->mLock);
    if (this->Empty()) {
        return std::optional<T>();
    } else {
        T data = front->mData;
        NodeType* newHead = *next(front);
        delete front;
        this->mSize--;
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
