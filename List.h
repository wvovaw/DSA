#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node* next;
};

template<typename T>
struct LinkedList
{
private:
    int lenght;
    Node<T>* head = nullptr;
public:
    bool is_empty()
    {
        return lenght==0?true:false;
    }

    void add(T data)
    {
        Node<T>* node = new Node<T>;
        node->data = data;
        if(head == nullptr)
            head = node;
        else
        {
        auto current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = node;
        }
        lenght++;
    }

    void add_at(T data, int index)
    {
        Node<T>* node = new Node<T>;
        node->data = data;
        if(lenght < index) return;
        else
        {
            auto current = head;
            for(int i = 0; i < index - 1; i++)
                current = current->next;
            node->next = current->next;
            current->next = node;   
        }
        lenght++;
    }
    
    void remove(T data)
    {
        auto current = head;
        auto previous = head;
        if (current->data == data)
            head = current->next;
        else { 
        while (current->data != data)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        }
        lenght--;
    }
    
    void remove_at(int index)
    {
        auto current = head;
        for(int i = 0; i < index - 1; i++)
            current = current->next;
        current->next = current->next->next;
        lenght--;        
    }

    int index_of(T data)
    {
        auto current = head;
        auto previous = head;
        if (current->data == data)
            return 0;
        int index = 0; 
        while (current->data != data)
        {
            previous = current;
            current = current->next;
            index++;
        }
        return index;
    }

    T item_at(int index)
    {
        auto current = head;
        for(int i = 0; i < index; i++)
            current = current->next;
        return current->data;
    }

    void print()
    {
        auto current = head;
        do 
        {
            std::cout << current->data << '\n';
            current = current->next;
        } while (current != nullptr);
    }
};
