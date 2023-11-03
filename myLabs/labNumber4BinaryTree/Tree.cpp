#include "Tree.h"

template<typename T>
Node<T>::Node()
{
    data = 0;
    previous = right = left = nullptr;
}

template<typename T>
Node<T>::Node(T info)
{
    data = info;
    previous = right = left = nullptr;
}

template<typename T>
void Tree<T>::push(T info)
{
    if (current == nullptr)
    {
        root = current = new Node<T>(info);
    }
    else if (info < current->data && current->left == nullptr)
    {
        current->left = new Node<T>(info);
        current->left->previous = current;
    }
    else if (info > current->data && current->right == nullptr)
    {
        current->right = new Node<T>(info);
        current->right->previous = current;
    }
    else if (info < current->data)
    {
        current = current->left;
        push(info);
    }
    else if (info > current->data)
    {
        current = current->right;
        push(info);
    }
    current = root;
}



template<typename T>
void Tree<T>::pop( T info)
{
    if (current == nullptr)
    {
        std::cout << "\nТакого элемента в дереве нету";
        return;
    }
    if (info < current->data)
    {
        current = current->left;
        pop(info);
    }
    else if (info > current->data)
    {
        current = current->right;
        pop(info);
    }
    else if (info == current->data)
    {
        Node<T>* tmp;
        if (current->left == nullptr && current->right == nullptr)
        {
            tmp = current;
            current = current->previous;
            if (current->right == tmp)
                current->right = nullptr;
            if (current->left == tmp)
                current->left = nullptr;
            delete tmp;
        }
        else if (current->right == nullptr)
        {
            tmp = current;
            if (current->previous->right == tmp)
                current->previous->right = current->left;
            if (current->previous->left == tmp)
                current->previous->left = current->left;
            current->previous = tmp->previous;
            delete tmp;
        }
        else if (current->left == nullptr)
        {
            tmp = current;
            if (current->previous->right == tmp)
                current->previous->right = current->right;
            if (current->previous->left == tmp)
                current->previous->left = current->right;
            current->previous = tmp->previous;
            delete tmp;
        }
        else
        {
            tmp = current->left;
            while (tmp->right != nullptr)
                tmp = tmp->right;
            tmp->right = current->right;
            current->right->previous = tmp;
            if (tmp->previous == current)
                tmp->previous = current->previous;
            tmp = current;
            if (current->previous->right == current)
                current->previous->right = current->left;
            if (current->previous->left == current)
                current->previous->left = current->left;
            if (tmp == root)
                root = root->left;
            delete tmp;
        }
        current = root;
    }
}

template<typename T>
int Tree<T>::peek()
{
    return this->root->data;
}


template<typename T>
void Tree<T>::print()
{
    printTree(root, 0, 0, -1);
}


template<typename T>
void Tree<T>::printTree(Node<T> * Root, int space, bool position, int info)
{
    if (Root == nullptr)
        return;
    printTree(Root->right, space + 1, false, info);      //вывод правого поддерева
    for (int i = 0; i < space; i++)
        std::cout << "    ";
    if (!position)
        std:: cout << "┌───";
    else
        std::cout << "└───";
    std::cout << Root->data << std::endl;
    printTree(Root->left, space + 1, true, info);
}

