#include <iostream>

template <typename T>
class LinkedList {

    //Linked list node definition
    struct Node {
        T data;
        Node* next_node = nullptr;
    };

    //Instance variables
    int list_length = 0;

    Node* tail_node;
    Node* head_node;
    Node* temp_node;

    auto insert_node(T, Node* next_node = nullptr );
    auto iterate(int bound = -1) ->void;
    auto check_bounds(int) -> void;

public:

    //Constructors
    LinkedList(T*, const int);    //Constructs a linked list from an existing array
    LinkedList();                 //Constructs an empty linked list

    //Destructor
    ~LinkedList();                //Deallocates the memory used by the list object

    //Methods
    auto for_each(void (*callback)(T) = nullptr) -> void; //Iterates the list and calls the "callback" for each element
    auto clear_list() -> void;
    auto append(T) -> T;
    auto prepend(T) -> T;
    auto insert(T, int) -> T;
    auto remove(int) -> void;
    auto operator[](const int&) -> T&;

};

#include "linkedlist.inl"