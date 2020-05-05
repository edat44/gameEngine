//
// Created by edat44 on 5/4/20.
//

#ifndef GAME_STACK_HPP
#define GAME_STACK_HPP

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <optional>

#define MIN_CAPACITY 10

template <typename T>
class Stack {
public:
    explicit Stack(size_t cap=MIN_CAPACITY) : data(nullptr), size(0), capacity(cap) {
        this->data = new T[this->capacity];
    }
    ~Stack();
    void Push(const T &element);
    std::optional<T> Pop();
    [[nodiscard]] bool Empty() const;
    void Print(std::ostream& out= std::cout) const;

    friend std::ostream& operator<<(std::ostream &out, const Stack &s) {
        out << "size: " << s.size << ", cap: " << s.capacity << std::endl;
        if (s.Empty()) {
            std::cout << "<Empty>";
        } else {
            for (size_t i = 0; i < s.size; i++) {
                out << s.data[i] << (i == s.size - 1 ? "" : ", ");
            }
        }
        out << std::endl;
        return out;
    }


private:
    int Resize(size_t newCapacity);
    void AdjustCapacity();

    T* data;
    size_t size;
    size_t capacity;
};

template <typename T>
Stack<T>::~Stack() {
    delete [] this->data;
    this->data = nullptr;
    this->size = 0;
}

template <typename T>
void Stack<T>::Push(const T &element) {
    assert(this->data != nullptr);
    this->AdjustCapacity();
    this->data[this->size++] = element;
}

template <typename T>
std::optional<T> Stack<T>::Pop() {
    assert(this->data != nullptr);
    if (this->Empty()) {
        return std::optional<T>();
    } else {
        T element = this->data[--this->size];
        this->AdjustCapacity();
        return element;
    }
}

template<typename T>
bool Stack<T>::Empty() const {
    return this->size == 0;
}

template <typename T>
void Stack<T>::Print(std::ostream& out) const {
    out << *this;
}

template <typename T>
int Stack<T>::Resize(size_t newCapacity) {
    assert(this->data != nullptr);

    T* newData = new T[newCapacity];
    std::copy(this->data, this->data + this->size, newData);
    delete [] this->data;

    this->data = newData;
    this->capacity = newCapacity;
    return this->capacity;
}

template <typename T>
void Stack<T>::AdjustCapacity() {
    if (this->size >= this->capacity) {
        this->Resize(this->size * 1.5);
    } else if (this->size <= this->capacity * 0.5) {
        this->Resize(std::max((int) (this->size * 0.75), MIN_CAPACITY));
    }
}




#endif //GAME_STACK_HPP
