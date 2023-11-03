#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> * previous;
    Node<T> * left;
    Node<T> * right;
    explicit Node(T info);
    Node ();
};

template <typename T>
class Tree
{
private:
    Node<T> * root;
    Node<T> * current;
public:
    Tree();
    void push(T info);

    void pop(T info);

    int peek();

    void print();
    void printTree(Node<T> * Root, int space, bool position, int info);

};

template<typename T>
Tree<T>::Tree()
{
    root = current = nullptr;
}


#endif //UNTITLED_TREE_H
