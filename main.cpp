#include <iostream>
#include "./linkedlists/linkedlist.h"

void printNumbers(int number) {
    std::cout << number << std::endl;
    return;
}

int main() {
    int numbers[5] = {0, 1, 2, 3, 4};
    LinkedList<int> list_numbers(numbers, 5);

    list_numbers.for_each(printNumbers);

    // list_numbers.append(20);
    // list_numbers.prepend(10);

    // list_numbers.for_each(printNumbers);

    // list_numbers.insert(50, 3);

    // list_numbers.remove(5);

    // list_numbers.for_each(printNumbers);

    list_numbers.clear_list();

    list_numbers.for_each(printNumbers);

    return 0;
}