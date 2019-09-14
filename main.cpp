#include <iostream>
//#include "List.h"
//#include "Stack.h"
//#include "Queue.h"
#include "BinarySearchTree.h"

int main()
{
    /*
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
    std::cout << "let's stack!\n";
    Stack<int>* Stack1 = new Stack<int>;
    Stack1->push(1); 
    Stack1->push(2);
    Stack1->push(3);
    Stack1->push(4);
    std::cout << "top: " << Stack1->top() << '\n';
    std::cout << "Pop 1 element\ntop: ";
    Stack1->pop();
    std::cout << Stack1->top() << '\n';
    std::cout << "add 1 new element\n";
    Stack1->push(10);
    std::cout << "Let's see all stack:\n";
    Stack1->print();    

    Queue<int>* Queue1 = new Queue<int>;
    Queue1->enqueue(5);
    Queue1->enqueue(4);
    Queue1->enqueue(3);
    Queue1->enqueue(2);
    Queue1->enqueue(1);
    std::cout << "Check all queue:\n";
    Queue1->print();
    std::cout << "Let's dequeue queue 2 times:\n";
    Queue1->dequeue();
    Queue1->dequeue();
    Queue1->print();
    std::cout << "Front: " << Queue1->getFront() << "\nBack: " << Queue1->getBack() << '\n';
*/
    BinTree<int>* BinTree1 = new BinTree<int>;
    int nums[10] = {2,5,9,1,3,4,8,6,0,7};
    int lenght = sizeof(nums) / sizeof(nums[0]);
    BinTree1->build(nums, lenght);
    auto node = BinTree1->root;
    //node = BinTree1->insert(node, nums[0]);
    BinTree1->printInorder(BinTree1->root);
    BinTree1->remove(9);
    std::cout << '\n';
    BinTree1->printInorder(BinTree1->root);
    BinTree1->remove(3);
    std::cout << '\n';
    BinTree1->printInorder(BinTree1->root);
    return 0;
}