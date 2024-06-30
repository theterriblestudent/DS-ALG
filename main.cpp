#include <iostream>
#include "./stack/stack.h"


int main() {
    int some_array[5] = {0, 1, 2, 3, 4};

    Stack<int> some_stack(some_array, 5);

    std::cout << some_stack.pop() << std::endl;
    std::cout << some_stack.pop() << std::endl;
    std::cout << some_stack.pop() << std::endl;


    return 0;
}