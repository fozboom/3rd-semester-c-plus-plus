#include <iostream>
#include <iomanip>
#include <vector>
#include "employee.h"



int main()
{
    std::vector<Employee> employees;
    Employee newEmployee;
    int command = inputNumber<int>();
    while(true)
    {
        std::cout << "Выберите команду\n" << "1 - Добавить информацию о сотруднике\n"
                  << "2 - Вывести информацию о сотруднике по ID\n"
                  << "3 - Вывести информацию о всех сотрудниках в виде таблицы\n";
        switch (command)
        {
            case 1:
                newEmployee.getEmployee((int) employees.size() + 1);
                employees.push_back(newEmployee);
                break;
            case 2:
                int workerID;
                std::cout << "Введите номер ID сотрудника - "; std:: cin >> workerID;


                break;
            case 3:
                break;
            case 4:
                return 1;
            default:
                std::cout << "Неизвестная команда";
        }
    }

    return 0;
}
