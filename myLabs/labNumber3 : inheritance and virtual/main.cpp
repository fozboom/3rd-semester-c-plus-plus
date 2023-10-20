#include "Computer.h"

int Computer::count = 0;
Computer* Computer::pComputers[MAX_SIZE];

int main()
{
    char choice;
    while(true)
    {
        std::cout << "\n'a' - добавление сведений о компьютере"
                     "\n'd' - вывести сведения обо всех компьютерах"
                     "\n'w' - записать все данные в файл"
                     "\n'r' - прочитать все данные из файла"
                     "\n'f' - завершить программу"
                     "\nВаш выбор: ";
        std::cin >> choice;
        rewind(stdin);
        switch(choice)
        {
            case 'a':
                Computer::add(); break;
            case 'd':
                Computer::display();
                break;
            case 'w':
                Computer::write(); break;
            case 'r':
                Computer::read(); break;
            case 'f':{
                Computer::freeMemory();
                exit(0);
            }
            default:
                std::cout << "\nНеизвестная команда";
        }
    }
}
