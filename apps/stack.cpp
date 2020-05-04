
#include <iostream>

#include "events/Stack.hpp"


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    Stack<int> q;
    q.print();
    for (int i = 0; i < 21; i++) {
        q.push(i);
        q.print();
    }
    for (int i = 0; i < 22; i++) {
        std::optional<int> element = q.pop();
        if (element) {
            std::cout << "Removing " << element.value() << std::endl;
        } else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }
}
