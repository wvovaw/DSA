#include <iostream>
template<typename T>
struct BTNode
{
    T data;
    BTNode<T>* left;
    BTNode<T>* right;
};
template<typename T>
struct BinTree
{
public:
    BTNode<T>* root;
    private: BTNode<T>* newNode(T data)
    {
        BTNode<T>* node = new BTNode<T>;
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    private: BTNode<T>* insert(BTNode<T>* node, T data)
    {
        if (node == nullptr)
            return newNode(data);
        if(data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }
    public: void build(T* data, int lenght)
    {
        BTNode<T>* node = newNode(data[0]); 
        root = node; 
        for (size_t i = 1; i < lenght; i++)
            node = insert(node, data[i]);     
    }
    void add(T data)
    {
        if (root == nullptr)
            root = newNode(data);
        else insert(root, data);
    }
    private: std::pair<BTNode<T>*, BTNode<T>*> FindWithParent(T data, BTNode<T>* parent)
    {
        BTNode<T>* current = root;
        parent = nullptr;
 
        while (current != nullptr)
        {
            if (current->data > data)
            {
                parent = current;
                current = current->left;
            }
            else if (current->data < data)
            {
                parent = current;
                current = current->right;
            }
            else break;
        }
        std::pair<BTNode<T>*, BTNode<T>*> nodes(current, parent);
        return nodes;
    }
    public: bool remove(T data)
    {
        BTNode<T>* current;
        BTNode<T>* parent = nullptr;
        auto nodes = FindWithParent(data, parent);
        current = nodes.first;
        parent = nodes.second; 
        if (current == nullptr)
            return false;
        // 1) If there is no childs on the right, left child stands instead of removed parent.
        if (current->right == nullptr)
        {
            if (parent == nullptr)
                root = current->left;
            else
            {   
                // If parent.data is greater than current.data then the left child of current node
                // becomes the left child of parent.
                if (current->data < parent->data)
                    parent->left = current->left;
                // If parent.data is less than current.data then the left child of current node
                // becomes the right child of parent. 
                else if (current->data > parent->data)
                    parent->right = current->left;
            }
        }
        // 2) If right child has no childs on it's left then it becomes instead of removed parent.
        else if (current->right->left == nullptr)
        {
            current->right->left = current->left;
            if (parent == nullptr)
                root = current->right;
            else
            {
                // If parent.data is greater than current.data then the right child of current node
                // becomes the left child of parent.
                if (current->data < parent->data)
                    parent->left = current->right;
                // If parent.data is less than current.data then the right child of current node
                // becomes the right child of parent.
                else if (current->data > parent->data)
                    parent->right = current->right;
            }
        }
        // 3) If right child has childs on it's left then
        // the most extrem left child from the right subtree becomes instead of removed parent.
        else
        {
            // Find the most extrem left node
            BTNode<T>* mostLeft = current->right->left;
            BTNode<T>* mostLeftParent = current->right;
            while (mostLeft->left != nullptr)
            {
                mostLeftParent = mostLeft;
                mostLeft = mostLeft->left;
            }
            // The left subtree of parent becomes the right subtree of the left node.
            mostLeftParent->left = mostLeft->right;
            // Left and right childs of the current node becomes the left and the right childs of the most extrem left
            mostLeft->left = current->left;
            mostLeft->right = current->right;
            if(parent == nullptr)
                root = mostLeft;
            else
            {
                // If parent.data is greater than current.data then the extrem left node
                // becomes the left child of parent.
                if (current->data < parent->data)
                    parent->left = mostLeft;
                // If parent.data is less than current.data then the extrem left node
                // becomes the right child of parent.
                else if (current->data > parent->data)
                    parent->right = mostLeft;
            }
        }
    }
    public: void printInorder (BTNode<T>* node)  
    {  
        if (node == nullptr)  
            return;  
        printInorder(node->left);  
        std::cout << node->data << ", ";  
        printInorder(node->right);  
    }  
};
