#include "Mystring.h"


int main()
{
    Mystring str1, str2, cmpStr, result;
    int choice;
    do
    {
        std::cout << "\nВыберите операцию:\n"
                     "0 - выход из программы\n"
                     "1 - ввести строку\n"
                     "2 - вывести строку\n"
                     "3 - сложить строки\n"
                     "4 - сравнить строки\n"
                     "5 - перевернуть строку\n"
                     "6 - привести к нижнему регистру\n"
                     "7 - привести к верхнему регистру\n"
                     "8 - использовать оператор ()\n"
                     "9 - получить символ строки по индексу\n";
        std::cin >> choice;
        switch (choice)
        {
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            case 1:
                std::cout << "Введите строку для str1: ";
                str1.inputStr();
                break;
            case 2:
                std::cout << "Строка str1: " << str1 << std::endl;
                break;
            case 3:
                std::cout << "Введите строку для str2: ";
                str2.inputStr();
                result = str1 + str2;
                std::cout << "Результат сложения: " << result << std::endl;
                break;
            case 4:
                std::cout << "Введите строку для сравнения с str1: ";
                cmpStr.inputStr();
                if (str1 == cmpStr)
                    std::cout << "Строки равны.\n";
                else
                    std::cout << "Строки не равны.\n";
                break;
            case 5:
                str1.reverse();
                std::cout << "Строка str1 после переворота: " << str1 << std::endl;
                break;
            case 6:
                str1.toLower();
                std::cout << "Строка str1 в нижнем регистре: " << str1 << std::endl;
                break;
            case 7:
                str1.toCaps();
                std::cout << "Строка str1 в верхнем регистре: " << str1 << std::endl;
                break;
            case 8:
                int first, last;
                std::cout << "Введите начальный и конечный индексы для оператора (): ";
                std::cin >> first; std::cin >> last;
                std::cout << "Результат операции (): ";
                str1(first, last);
                std::cout << std::endl;
                break;
            case 9:
                std::cout << "Введите индекс, который надо получить из строки str1 - ";
                int i;
                std::cin >> i;
                std::cout << "Символ - " << str1[i];
                break;
            default:
                std::cout << "Недопустимая операция. Попробуйте снова.\n";
                break;
        }
    } while (choice != 0);
    return 0;
}


