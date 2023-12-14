#include "Computer.h"

void add(std::vector<std::unique_ptr<Computer>>& computerList, int count)
{
    char choice;
    std::cout << "\n'd' для добавления Desktop"
              << "\n'p' для добавления PortableDevice"
              << "\n'm' для добавления Monoblock"
              << "\n't' для добавления TabletComputer"
              << "\n'l' для добавления Laptop"
              << "\nВаш выбор: ";

    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 'd': computerList.push_back(std::make_unique<Desktop>()); break;
        case 'p': computerList.push_back(std::make_unique<PortableDevice>()); break;
        case 'm': computerList.push_back(std::make_unique<Monoblock>()); break;
        case 't': computerList.push_back(std::make_unique<TabletComputer>()); break;
        case 'l': computerList.push_back(std::make_unique<Laptop>()); break;
        default: std::cout << "Неизвестная команда"; return;
    }
    computerList[count]->inputData();
    count++;
}

void display(std::vector<std::unique_ptr<Computer>>& computerList)
{
    for(auto& computer : computerList) {
        computer->print();
    }
}

int main()
{
    int count = 0;
    std::vector<std::unique_ptr<Computer>> computerArray;
    char choice;
    while(true)
    {
        std::cout << "\n'a' - добавление сведений о компьютере"
                     "\n'd' - вывести сведения обо всех компьютерах"
                     "\n'f' - завершить программу"
                     "\nВаш выбор: ";
        std::cin >> choice;
        rewind(stdin);
        switch(choice)
        {
            case 'a':
                add(computerArray, count);
            case 'd':
                display(computerArray);
                break;
            case 'f':
                exit(0);
            default:
                std::cout << "\nНеизвестная команда";
        }
    }
}
