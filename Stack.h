#include <iostream>
#include "Node.h"
template<typename T>
struct Stack
{
private:
    Node<T>* last = nullptr;
    int size = 0;
public:
    void push(T data)
    {
        Node<T>* node = new Node<T>;
        node->data = data;
        if(size == 0) {
            last = node;
            size++;
            return;
        }
        else {
            node->next = last;
            last = node;
        }
        
    }
    void pop()
    {
        last = last->next;
    }
    T top()
    {        
        return last->data;
    }
    void print()
    {
        Node<T>* current;
        current = last;
        int count = 0;
        while (current != nullptr)
        {
            std::cout << count++ << ": " << current->data << '\n';
            current = current->next;
        }      
    }
};
