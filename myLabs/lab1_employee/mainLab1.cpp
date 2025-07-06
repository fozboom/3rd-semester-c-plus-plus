#include "employee.h"

/*                                                          Гнетецкого Даниеля
 *                                                              Вариант 4
 *
 *     Условие: Создать класс employee. Класс должен включать поле int для хранения номера сотрудника и поле float для хранения величины его оклада.
 *              Расширить содержание класса employee, включив в него класс date и перечисление retype. Объект класса date использовать для хранения
 *              даты приема сотрудника на работу. Перечисление использовать для хранения статуса сотрудника: лаборант, секретарь, менеджер и т. д.
 *              Разработать методы get employ() и putemploy(), предназначенные соответственно для ввода и отображения информации о сотруднике. Написать
 *              программу, которая будет выдавать сведения о сотрудниках.
*/
int Employee::counter = 0;

int main()
{
    std::vector<Employee> employees;                                                                                    //вектор в котором хранятся объекты
    while(true)
    {
        Employee newEmployee, totalSalary;                                                                                           //объект, который будет добавляться в вектор
        std::cout << "\nВыберите команду\n" << "1 - Добавить информацию о сотруднике\n"
                  << "2 - Вывести информацию о сотруднике по ID\n"
                  << "3 - Вывести информацию о всех сотрудниках в виде таблицы\n"
                  << "4 - Записать информацию в текстовый файл\n"
                  << "5 - Считать информацию из текстового файла\n"
                  << "6 - Увеличить зарплату работнику\n"
                  << "7 - Уменьшить зарплату работнику\n"
                  << "8 - сравнить тип профессии\n";
        int command = inputNumber<int>(1, 8), ID1, ID2, ID;                                                                     //ввод типа команды
        float plusSalary;
        switch (command)
        {
            case 1:
                newEmployee.getEmployee();
                employees.push_back(newEmployee);                                                                       //создание объекта и добавление его в вектор
                break;
            case 2:
                int workerID;
                std::cout << "Введите номер ID сотрудника - "; std:: cin >> workerID;
                employees[workerID - 1].putEmployee();                                                                  //вывод информации о сотруднике по его ID
                break;
            case 3:
                printEmployeeTable(employees);                                                                          //вывод информации о сотрудниках в виде таблицы
                break;
            case 4:
                writeTextFile(employees);                                                                            //запись данных в текстовый файл
                break;
            case 5:
                employees = readTextFile();                                                                             //чтение данных из текстового файла
                break;
            case 6:
                std::cout << "Введите ID сотрудников, которому надо увеличить зарплату:\n";
                ID = inputNumber(0, static_cast<int>(employees.size()));
                std::cout << "Введите, на какую сумму увеличить зарплату:\n";
                plusSalary = inputNumber<float>(0.0, 10000.0);
                employees[ID - 1] = employees[ID - 1] + plusSalary;
                std::cout << "Новая зарплата: " << employees[ID - 1].getSalary();
                break;
            case 7:
                std::cout << "Введите ID сотрудников, которому надо уменьшить зарплату:\n";
                ID = inputNumber(0, static_cast<int>(employees.size()));
                std::cout << "Введите, на какую сумму уменьшить зарплату:\n";
                plusSalary = inputNumber<float>(0.0,   employees[ID-1].getSalary());
                employees[ID - 1] = employees[ID - 1] - plusSalary;
                std::cout << "Новая зарплата: " << employees[ID - 1].getSalary();
                break;
            case 8:
                std::cout << "Введите ID сотрудников, профессии которых надо сравнить:\n";
                ID1 = inputNumber(0, static_cast<int>(employees.size()));
                ID2 = inputNumber(0, static_cast<int>(employees.size()));
                if (employees[ID1 - 1] & employees[ID2 - 1])
                    std::cout << "У работников одинаковые профессии";
                else
                    std::cout << "У работников разные профессии";
                break;
            case 1000:
                return 0;                                                                                               //завершение программы
            default:
                std::cout << "Неизвестная команда";
        }
    }

}
