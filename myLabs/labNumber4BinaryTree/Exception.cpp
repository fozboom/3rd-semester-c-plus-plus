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
        throw ExceptionInputNumber(1, "Ошибка ввода числа");
    }
    return num;
}

Exception::Exception(): code(0)
{
    strncpy(message, "ERROR", sizeof ("ERROR"));
}

Exception::Exception(int x, const char* mes): code(x)
{
    strncpy(message, mes, sizeof(message));
}

void Exception::showErrorMessage()
{
    std::cout << "Error " << code << ": " << message << std::endl;
}
