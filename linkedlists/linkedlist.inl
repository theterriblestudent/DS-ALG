#include <iostream>

template <typename T>
LinkedList<T>::LinkedList(T* array, const int ARRAY_LENGTH) {
    list_length = ARRAY_LENGTH;
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        if (i == 0)
            head_node = insert_node(array[i]);
        else {
            iterate();
            temp_node->next_node = insert_node(array[i]);
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList() {
    head_node = nullptr;
    tail_node = nullptr;
    list_length = 0;
}

template <typename T>
void LinkedList<T>::iterate(int bound) {
    if (bound == -1) bound = list_length;

    int _iterator = 1;

    temp_node = head_node;
    while(temp_node->next_node && _iterator < bound) {
        temp_node = temp_node->next_node;
        _iterator++;
    }
}

template <typename T>
auto LinkedList<T>::insert_node(T element, Node* next_node) {
    Node* _temp_node = new Node;
    _temp_node->next_node = next_node;
    _temp_node->data = element;

    return _temp_node;
}
template <typename T>
void LinkedList<T>::check_bounds(int index) {
    if (index > list_length || index < 1)
        throw "Index out of bounds, boss!";
}

template <typename T>
void LinkedList<T>::for_each(void (*callback)(T)) {
    temp_node = head_node;
    while(temp_node) {
        callback(temp_node->data);
        temp_node = temp_node->next_node;
    }
}

template<typename T>
void LinkedList<T>::clear_list() {
    while (head_node) {
        temp_node = head_node->next_node;
        delete head_node;
        head_node = temp_node;
    }

    list_length = 0;
}

template <typename T>
T LinkedList<T>::append(T element) {
    iterate();
    temp_node->next_node = insert_node(element);

    list_length++;

    return element;
}

template <typename T>
T LinkedList<T>::prepend(T element) {
    temp_node = head_node;
    head_node = insert_node(element, temp_node);

    list_length++;

    return element;
}

template <typename T>
T LinkedList<T>::insert(T element, int index) {
    check_bounds(index);

    if (index == 1) 
        return prepend(element);

    if (index == list_length)
        return append(element);

    iterate(index - 1);

    Node* _temp_node = temp_node->next_node;
    temp_node->next_node = insert_node(element, _temp_node);
    list_length++;

    return element;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    check_bounds(index);

    if (index == 1) {
        temp_node = head_node->next_node;
        delete head_node;
        head_node = temp_node;

        list_length--;
        return;
    }

    iterate(index - 1);
    Node* _temp_node = temp_node->next_node;
    _temp_node = _temp_node->next_node;

    delete temp_node->next_node;
    temp_node->next_node = _temp_node;

    list_length--;
}

template <typename T>
T& LinkedList<T>::operator[](const int& index) {
    if (index > list_length - 1 || index < 0)
        throw "Index out of bounds, boss!";

    int _iterator = 0;
    temp_node = head_node;

    while(temp_node->next_node && _iterator < index) {
        temp_node = temp_node->next_node;
        _iterator++;
    }

    return temp_node->data;
}


template <typename T>
LinkedList<T>::~LinkedList() {
    clear_list();
}

