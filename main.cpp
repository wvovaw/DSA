#include <iostream>
#include "List.h"

int main()
{
    LinkedList<int>* List1; 
    List1 = new LinkedList<int>();
    List1->add(1);
    List1->add(2);
    List1->add(3);
    List1->add(4);
    List1->add(5);
    List1->add(6);
    std::cout << "There is the List1:\n";
    List1->print();
    std::cout << "Remove 2 and 5:\n";
    List1->remove(2);
    List1->remove(5);
    List1->print();
    std::cout << "Add 10 at 2 and 15 at the end:\n";
    List1->add_at(10, 2);
    List1->add_at(15, 5);
    List1->print();
    std::cout << "Remove at 3:\n";
    List1->remove_at(3);
    List1->print();
    std::cout << "Index of 10: " << List1->index_of(10) << '\n';
    std::cout << "Item at 4: " << List1->item_at(4);
    delete List1;
    std::cin.get();
    return 0;
}