#include <iostream>
#include "./linkedlists/linkedlist.h"

void printNumbers(int number) {
    std::cout << number << std::endl;
    return;
}

int main() {
    int numbers[5] = {0, 1, 2, 3, 4};
    LinkedList<int> list_numbers(numbers, 5);
    
    std::cout << list_numbers[2] << std::endl;

    return 0;
}