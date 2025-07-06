#include "Tree.h"
#include "Tree.cpp"
#include "Computer.h"
#include "Algorithm.h"



int main()
{
    Tree<Desktop> tree;
    Desktop x;
    char choice;
    bool filterByPrice = true;
    bool filterByWeight = true;
    double minWeight = 10, minPrice = 100, maxWeight = 1500, maxPrice = 4000;

    while(true)
    {
        std::cout << "\n'a' - добавление"
                     "\n'd' - удаление"
                     "\n'c' - удалить дерево"
                     "\n'r' - прочитать дерево из файла"
                     "\n'w' - записать дерево в файл"
                     "\n's' - поиск согласно фильтру"
                     "\n'b' - бинарный поиск"
                     "\n'e' - кол-во узлов в дереве"
                     "\n'f' - завершить программу"
                     "\nВаш выбор: ";
        std::cin >> choice;
        rewind(stdin);
        try {
            switch (choice)
            {
                case 'a': {
                    x.inputData();
                    tree.push(x);
                    tree.print();
                    break;
                }
                case 'd': {
                    x.inputData();
                    tree.pop(x);
                    tree.print();
                    break;
                }
                case 'c': {
                    tree.clear();
                    tree.print();
                    break;
                }
                case 'b': {
                    x.setPrice();
                    auto result = Algorithm::find(tree.begin(), tree.end(), x);
                    if(result != tree.end())
                    {
                        std::cout << "\nЭлемент есть в дереве\n";
                    } else {
                        std::cout << "\nТакого элемента в дереве нету\n";
                    }
                    break;
                }
                case 'w': {
                    tree.writeTreeToFile("TREE.txt");
                    break;
                }
                case 'r': {
                    tree.clear();
                    tree.readTreeFromFile("TREE.txt");
                    tree.print();
                    break;
                }
                case 's':{
                    Tree<Desktop> filtrationTree;
                    Algorithm::searchByFiltration(tree.begin(), tree.end(),filtrationTree, [&](const Desktop& object){
                        bool flag = false;
                        if(filterByPrice)
                        {
                            if (object.getPrice() < maxPrice && object.getPrice() > minPrice)
                                flag = true;
                        }
                        if (filterByWeight)
                        {
                            if ((object.getWeight() < maxWeight && object.getWeight() > minWeight) && flag)
                                flag = true;
                        }
                        return flag;
                    });

                    filtrationTree.print();
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
            std::cerr << ex.what();
        }catch (ExceptionInputNumber &ex) {
            std::cerr << ex.what();
        }catch (std::bad_alloc& ex){
            std::cerr << ex.what();
            exit(EXIT_FAILURE);
        }
    }


}