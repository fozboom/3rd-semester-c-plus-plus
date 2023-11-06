#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H
#include "Exception.h"
#include <iostream>
#include <fstream>

template<typename T>
class Tree;

template <typename T>
struct Node
{
    T data;
    Node<T> * previous;
    Node<T> * left;
    Node<T> * right;

    explicit Node(T info);
    Node ();

    Node<T>* operator++();
    Node<T>* operator--();
    Node<T>* operator~();
};




template <typename T>
class Tree
{
private:
    Node<T> * root;
    Node<T> * current;
public:
    Node<T> * getRoot(){return root;}
    void setRoot(Node<T>* newRoot) {root = newRoot;}

    Tree();

    void push(T info);

    void pop(T info);
    void deleteNode (Node<T> ** Root, T info);

    int peek();

    void print();
    void printTree(Node<T> * root, int space, bool position);

    void serializeTree(std::ostream& out, Node<T>* node);
    void deserializeTree(std::istream& in);

    void writeTreeToFile(const char* filename);
    void readTreeFromFile(const char* filename);

    void clearTree (Node<T> * node);
    void clear();


};






#endif //UNTITLED_TREE_H
