#include <iostream>
#include "stack.h"

template <typename T>
Stack<T>::Stack() {
    list = new LinkedList<T>();
}

template <typename T>
Stack<T>::Stack(T* initial_array, const int& array_size) {
    list = new LinkedList<T>(initial_array, array_size);
}

template <typename T>
Stack<T>::~Stack() {
    delete list;
}

template <typename T>
int Stack<T>::get_length() {
    return list->get_length();
}

template <typename T>
bool Stack<T>::is_empty() {
    return (list->get_length() == 0);
}

template <typename T>
T Stack<T>::top() {
    return (*list)[list->get_length() - 1];
}

template <typename T>
T Stack<T>::pop() {
    T temp_value =  (*list)[list->get_length() - 1];
    list->remove(list->get_length());
    return temp_value;
}

template <typename T>
void Stack<T>::push(T element) {
    list->append(element);
}