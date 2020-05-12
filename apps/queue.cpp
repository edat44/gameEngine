
#include <iostream>

#include "containers/Queue.hpp"


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    Queue<int> q;
    q.Print();
    for (int i = 0; i < 21; i++) {
        q.Enqueue(i);
        q.Print();
    }
    for (int i = 0; i < 22; i++) {
        std::optional<int> element = q.Dequeue();
        if (element) {
            std::cout << "Removed " << element.value() << std::endl;
        } else {
            std::cout << "Stack is Empty!" << std::endl;
        }
        q.Print();
    }
    q.Enqueue(5);
    q.Print();
}
