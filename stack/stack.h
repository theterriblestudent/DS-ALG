#ifndef STACK_H
#define STACK_H

#include "../linkedlists/linkedlist.h"

template<typename T>
class Stack {

private:
    LinkedList<T> *list;

public:
    //Member variables

    //Constructors and Destructors
    Stack();
    Stack(T* initial_array, const int& array_size);
    ~Stack();

    //Methods
    auto get_length(void) -> int;
    auto is_empty(void) -> bool;
    auto top(void) -> T;
    auto push(T element) -> void;
    auto pop(void) -> T;
};

#include "stack.inl"

#endif //STACK_H