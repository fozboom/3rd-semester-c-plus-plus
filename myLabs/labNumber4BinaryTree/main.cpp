#include "Tree.h"
#include "Tree.cpp"



int main()
{
    Tree<int> tree;
    int x;
    char choice;
    while(true)
    {
        std::cout << "\n'a' - добавление"
                     "\n'd' - удаление"
                     "\n'c' - удалить дерево"
                     "\n'r' - прочитать дерево из файла"
                     "\n'w' - записать дерево в файл"
                     "\n'f' - завершить программу"
                     "\nВаш выбор: ";
        std::cin >> choice;
        rewind(stdin);
        try {
            switch (choice)
            {
                case 'a': {
                    x = inputNumber();
                    tree.push(x);
                    tree.print();
                    break;
                }
                case 'd': {
                    x = inputNumber();
                    tree.pop(x);
                    tree.print();
                    break;
                }
                case 'c': {
                    tree.clear();
                    tree.print();
                    break;
                }
                case 'w': {
                    tree.writeTreeToFile("TREE");
                    break;
                }
                case 'r': {
                    tree.clear();
                    tree.readTreeFromFile("TREE");
                    tree.print();
                    break;
                }
                case 'f': {
                    tree.clear();
                    exit(0);
                }
                default:
                    std::cout << "\nНеизвестная команда";
            }

        }catch (ExceptionFile& ex){
            ex.showErrorMessage();
        }catch (ExceptionInputNumber &ex) {
            ex.showErrorMessage();
        }catch (std::bad_alloc& ex){
            ex.what();
            exit(EXIT_FAILURE);
        }
    }

}