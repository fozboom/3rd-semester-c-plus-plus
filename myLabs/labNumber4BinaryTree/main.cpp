#include "Tree.h"
#include "Tree.cpp"

int main()
{
    Tree<int> tree;
    int x;
    char choice;
    tree.push(10);
    tree.push(5);
    tree.push(15);
    tree.push(2);
    tree.push(7);
    tree.push(12);
    tree.push(20);
    tree.push(1);
    tree.push(3);
    tree.push(6);
    tree.push(9);
    tree.push(18);
    tree.push(25);
    tree.pop(10);
    tree.print();
    while(true)
    {
        std::cout << "\n'a' - добавление"
                     "\n'd' - удаление"
                     "\n'f' - завершить программу"
                     "\nВаш выбор: ";
        std::cin >> choice;
        rewind(stdin);
        switch(choice)
        {
            case 'a':
            {
                rewind(stdin);
                std::cin >> x;
                tree.push(x);
                tree.print();
                break;
            }
            case 'd':
            {
                std::cin >> x;
                tree.pop(x);
                tree.print();
                break;
            }
            case 'f':{
                exit(0);
            }
            default:
                std::cout << "\nНеизвестная команда";
        }
    }
//    tree.push(7);
//    tree.push(3);
//    tree.push(9);
//    tree.push(4);
//    tree.push(1);
//    tree.push(6);
//    tree.pop(4);
//    tree.print();
    return 0;
}