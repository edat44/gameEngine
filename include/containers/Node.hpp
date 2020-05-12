//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_NODE_HPP
#define GAME_NODE_HPP

#include <cassert>

namespace game::containers {

template <typename T>
class Node {
public:
    Node() = delete;
    explicit Node(T data) : data(data), next(nullptr), prev(nullptr) {}
    T data;
    Node<T>* *Next() { return &next; }
    Node<T>* *Prev() { return &prev; }
    Node<T>* next;
    Node<T>* prev;

    T& operator*() {
        return this->data;
    }

    T& operator->() {
        return this->data;
    }
};

template <typename Type, typename UnqualifiedType = std::remove_cv_t<Type>>
class NodeForwardIterator : public std::iterator<std::forward_iterator_tag,
                                                 UnqualifiedType,
                                                 std::ptrdiff_t,
                                                 Type*,
                                                 Type&> {
public:
    explicit NodeForwardIterator (Node<Type>* temp) : itr(temp) {}
    explicit NodeForwardIterator (nullptr_t) : itr(nullptr) {}

    NodeForwardIterator() = default;

    void swap(NodeForwardIterator& other) noexcept {
        std::swap(itr, other.itr);
    }

    NodeForwardIterator& operator++() { // Pre-increment
        assert(itr != nullptr && "Out-of-bounds iterator increment!");
        itr = itr->next;
        return *this;
    }

    NodeForwardIterator operator++(int) { // Post-increment
        assert(itr != nullptr && "Out-of-bounds iterator increment!");
        NodeForwardIterator tmp(*this);
        itr = itr->next;
        return tmp;
    }

    template <typename OtherType>
    bool operator == (const NodeForwardIterator<OtherType>& rhs) const {
        return itr == rhs.itr;
    }

    template <typename OtherType>
    bool operator!=(const NodeForwardIterator<OtherType>& rhs) const {
        return !(*this == rhs);
    }

    Type& operator*() const {
        assert(itr != nullptr && "Invalid iterator dereference");
        return itr->data;
    }

    Type& operator->() const {
        assert(itr != nullptr && "Invalid iterator dereference");
        return itr->data;
    }

    Node<Type>* GetNode() const {
        return itr;
    }

    // One-way conversion to const iterator;
    explicit operator NodeForwardIterator<const Type>() const {
        return NodeForwardIterator<const Type>(itr);
    }

private:
    Node<Type>* itr;
};


} // ns game::containers

#endif //GAME_NODE_HPP
