#include "Tree.h"

template<typename T>
void Tree<T>::printTree(Node<T> * Root, int space, bool position)
{
    if (Root == nullptr)
        return;
    printTree(++(*Root), space + 1, false);      //вывод правого поддерева
    for (int i = 0; i < space; i++)
        std::cout << "    ";
    if (!position)
        std:: cout << "┌───";
    else
        std::cout << "└───";
    std::cout << Root->data << std::endl;
    printTree(--(*Root), space + 1, true);
}

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
    deleteNode(&root, info);
}

template<typename T>
int Tree<T>::peek()
{
    return this->root->data;
}


template<typename T>
void Tree<T>::print()
{
    printTree(root, 0, false);
}



template<typename T>
void Tree<T>::deleteNode(Node<T> **Root, T info)
{
    if (*Root == nullptr)
    {
        std::cout << "\nВ дереве нет элемента "  << info << std::endl;
        return;
    }
    else if ((*Root)->data > info)
    {
        deleteNode(&(*Root)->left, info);
    }
    else if ((*Root)->data < info)
    {
        deleteNode(&(*Root)->right, info);
    }
    else if ((*Root)->data == info)
    {
        Node<T> * tmp;
        if((*Root)->right == nullptr)
        {
            tmp = *Root;
            (*Root) = (*Root)->left;
            delete tmp;
        }
        else if((*Root)->left == nullptr)
        {
            tmp = *Root;
            (*Root) = (*Root)->right;
            delete tmp;
        }
        else
        {
            tmp = (*Root)->left;
            while(tmp->right != nullptr)
            {
                tmp = tmp->right;
            }
            tmp->right = (*Root)->right;
            (*Root)->right->previous = tmp;
            tmp = (*Root);
            (*Root) = (*Root)->left;
            delete tmp;

        }
    }
}

template<typename T>
Tree<T>::Tree()
{
    root = current = nullptr;
}
template <typename T>
void Tree<T>::writeTreeToFile(const char* filename) const
{
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    writeTreeNodeToFile(outFile, root);

    outFile.close();
}

template <typename T>
void Tree<T>::writeTreeNodeToFile(std::ostream& os, Node<T>* node) const
{
    if (node)
    {
        os.write(reinterpret_cast<const char*>(&node->data), sizeof(T));
        writeTreeNodeToFile(os, node->left);
        writeTreeNodeToFile(os, node->right);
    }
}

template <typename T>
void Tree<T>::readTreeFromFile(const char* filename)
{
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    clear();

    root = readTreeNodeFromFile(inFile);

    inFile.close();
}

template <typename T>
Node<T>* Tree<T>::readTreeNodeFromFile(std::istream& is)
{
    T data;
    is.read(reinterpret_cast<char*>(&data), sizeof(T));

    if (is.eof())
    {
        return nullptr;
    }

    Node<T>* node = new Node<T>(data);
    node->left = readTreeNodeFromFile(is);
    node->right = readTreeNodeFromFile(is);

    return node;
}





template <typename T>
void Tree<T>::clearTree(Node<T>* node) {
    if (node)
    {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
    else
        return;
}

template <typename T>
void Tree<T>::clear()
{
    clearTree(root);
    root = nullptr;
    current = nullptr;
}

template<typename T>
Node<T> *Node<T>::operator~() {
    return previous;
}

template<typename T>
Node<T> *Node<T>::operator--() {
    return left;
}

template<typename T>
Node<T> *Node<T>::operator++() {
    return right;
}




template <typename T>
Node<T> *Tree<T>::findMimElement (Node<T> *_root) const
{
    if (root == nullptr)
        return nullptr;
    while (_root->left != nullptr)
        _root = _root->left;

    return _root;
}


