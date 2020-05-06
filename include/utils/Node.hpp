//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_NODE_HPP
#define GAME_NODE_HPP

template <typename T>
struct Node;

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
};


#endif //GAME_NODE_HPP
