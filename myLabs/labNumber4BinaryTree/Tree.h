#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H
#include "Exception.h"
#include <iostream>
#include <fstream>
#include <iterator>

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
    static Node<T>* findNextNode(Node<T> *value, bool forward)
    {
        Node<T> *nextNode = nullptr;  // Инициализация указателя null'ом.
        Node<T> * move = forward ? value->right : value->left;
        Node<T> * check = forward ? value->left : value->right;

        if (move)
        {
            nextNode = move;
            while (nextNode->left)
            {
                nextNode = nextNode->left;
            }
        }
        else if (value->previous)
        {
            if (value->previous->right == check)
            {
                do
                {
                    nextNode = nextNode->previous;
                }while (nextNode->previous != nullptr && nextNode != nextNode->previous->left);
                nextNode = nextNode->previous;
            }
            else
            {
                nextNode = nextNode->previous;
            }
        }

        return nextNode;
    }


    template <bool isConst>
    class TreeIterator
    {
    private:
        Node<T>* value;
    public:
        using value_type = T;
        using type = std::conditional_t<isConst, const T, T>;
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using pointer = type*;
        using reference = type&;

        explicit TreeIterator(Node<T>* val): value(val){};
        TreeIterator(TreeIterator& object): value(object.value){};

        bool operator == (const TreeIterator& object) const
        {
            return this->value == object->value;
        }

        bool operator != (const TreeIterator& object) const
        {
            return this->value != object.value;
        }
        TreeIterator& operator ++ ()
        {
            value = findNextNode(value, true);
            return *this;
        }

        TreeIterator& operator -- ()
        {
            value = findNextNode(value, false);
            return *this;
        }
        TreeIterator operator ++ (int)
        {
            auto iter = *this;
            ++(*this);
            return iter;
        }
        TreeIterator operator -- (int)
        {
            auto iter = *this;
            --(*this);
            return iter;
        }
        reference operator * ()
        {
            return value->data;
        }
        pointer operator->()
        {
            return &(this->operator*());
        }

        const type& operator*() const
        {
            return value->data;
        }

        const type* operator->() const
        {
            return &(this->operator*());
        }

        void writeObjectToFIle (std::ostream& os)
        {
            os.write(reinterpret_cast<char*>(*this), sizeof (*this));
        }

        void readObjectFromFile (std::istream& is)
        {
            is.read(reinterpret_cast<char*>(*this), sizeof(*this));
        }
    };

    using value_type = T;
    using iterator = TreeIterator<false>;
    using const_iterator = TreeIterator<true>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;


private:
    void deleteNode (Node<T> ** Root, T info);
    void printTree(Node<T> * root, int space, bool position);

    void clearTree (Node<T> * node);
    Node<T>* findMimElement(Node<T>* _root) const;
public:
    Node<T> * getRoot(){return root;}
    void setRoot(Node<T>* newRoot) {root = newRoot;}
    Tree();
    void push(T info);
    void pop(T info);
    int peek();
    void print();
    void writeTreeToFile(const char* filename, Node<T>* root);
    void readTreeFromFile(const char* filename, Tree<T>& tree);
    void clear();

    iterator begin() const
    {
        return iterator(findMimElement(root));

    }
    iterator end() const
    {
        return iterator (nullptr);
    }

    const_iterator cbegin() const
    {
        return const_iterator (findMimElement(root));
    }
    const_iterator cend() const
    {
        return const_iterator (nullptr);
    }

    reverse_iterator rbegin() const
    {
        return std::make_reverse_iterator(end());
    }
    reverse_iterator rend() const
    {
        return std::make_reverse_iterator(begin());
    }

    const_reverse_iterator crbegin() const
    {
        return std::make_reverse_iterator(cend());
    }
    const_reverse_iterator crend() const
    {
        return std::make_reverse_iterator(cbegin());
    }


    void writeTreeNodeToFile(std::ostream& os, Node<T>* node) const;
    void readTreeFromFile(const char* filename);
    Node<T>* readTreeNodeFromFile(std::istream& is);
    void writeTreeToFile(const char* filename) const;


};




#endif //UNTITLED_TREE_H
