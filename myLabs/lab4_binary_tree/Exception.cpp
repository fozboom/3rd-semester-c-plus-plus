#include "Exception.h"

int inputNumber()
{
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw ExceptionInputNumber("Ошибка ввода числа");
    }
    return num;
}


