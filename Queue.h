#include <iostream>
#include "Node.h"
template<typename T>
struct Queue
{
private:
    Node<T>* front = nullptr;
    Node<T>* back = nullptr;
    int size = 0;
public:
    bool empty()
    {
        if(size == 0) return true;
        else return false;
    }
    int getSize()
    {
        return this->size;
    }
    T getFront()
    {
        return front->data;
    }
    T getBack()
    {
        return back->data;
    }
    void enqueue(T data)
    {
        Node<T>* node = new Node<T>;
        node->data = data;
        if (size == 0) {
            front = node;
        }
        else if(size == 1) {
            back = node;      
            front->next = back;
        }
        else {
            back->next = node;
            back = node;
        }
        size++;
    }
    void dequeue()
    {
        front = front->next;
        size--; 
    }
    void print()
    {
        Node<T>* current = front;
        int count = 0;
        while (current != nullptr)
        {
            std::cout << count++ << ": " << current->data << '\n';
            current = current->next;
        }      
    }
};