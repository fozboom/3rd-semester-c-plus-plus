#include "employee.h"

int Employee::counter = 0;

int main()
{
    std::vector<Employee> employees;
    while(true)
    {
        Employee newEmployee;
        std::cout << "\nВыберите команду\n" << "1 - Добавить информацию о сотруднике\n"
                  << "2 - Вывести информацию о сотруднике по ID\n"
                  << "3 - Вывести информацию о всех сотрудниках в виде таблицы\n"
                  << "4 - Завершить программу\n";
        int command = inputNumber<int>(1, 4);
        switch (command)
        {
            case 1:
                newEmployee.getEmployee();
                employees.push_back(newEmployee);
                break;
            case 2:
                int workerID;
                std::cout << "Введите номер ID сотрудника - "; std:: cin >> workerID;
                employees[workerID - 1].putEmployee();
                break;
            case 3:
                printEmployeeTable(employees);
                break;
            case 4:
                return 0;
            default:
                std::cout << "Неизвестная команда";
        }
    }
}
