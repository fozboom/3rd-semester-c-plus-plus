#include "employee.h"

//конструктор с параметрами для установления даты
Employee::Date::Date(int day, int month, int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}



//конструктор с параметрами
Employee::Employee(float salary, Date date, employeeType currentEmployee)
{
    salary = salary;
    date = date;
    currentEmployee = currentEmployee;
    numberOfEmployee = ++counter;
}



//методы для установления даты
void Employee::Date::setDay(int day)
{
    m_day = day;
}
void Employee::Date::setMonth(int month)
{
    m_month = month;
}
void Employee::Date::setYear(int year)
{
    m_year = year;
}



//метод для ввода информации о сотруднике
void Employee::getEmployee()
{
    std::cout << "Введите число даты\n";
    date.setDay((inputNumber<int>(1, 31)));
    std::cout << "Введите месяц\n";
    date.setMonth((inputNumber<int>(1, 12)));
    std::cout << "Введите год\n";
    date.setYear(((inputNumber<int>(1000, 3000))));

    std::cout << "Введите заработную плату\n";
    salary = inputNumber<float>(0.0, 1000000.0);
    std::cout << "Введите тип профессии\n";
    std::cout << "\n1 - программист" << "\n2 - врач" << "\n3 - банкир" << "\n4 - юрист" << "\n5 - учитель" << "\n6 - священник";
    int typeProfession = inputNumber<int>(0, countEmployeeType);
    m_currentEmployee = static_cast<employeeType>(typeProfession);
    numberOfEmployee = ++counter;
}



//метод для получения информации о сотруднике
void Employee::putEmployee()
{
    std::cout << "\nИнформация о сотруднике №" << numberOfEmployee << ":\n";
    std::cout << "Дата приема на работу: \t" << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << std::endl;
    std::cout << "Заработная плата: \t" << salary << " рублей";
    std::cout << "\nДолжность: ";
    switchTypeProfession(m_currentEmployee);
}



//шаблонная функция для ввода числа с проверкой
template <typename T>
T inputNumber (T a, T b)
{
    while (true)
    {
        T x;
        std::cin >> x;
        if (std::cin.fail() || x < a || x > b)                                                                          //если предыдущее извлечение не удалось
        {
            std::cout << "Ошибка ввода числа\n";
            std::cin.clear();                                                                                           //возвращаем в нормальный режим
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                                 //очистка всех символов до \n
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
    }
}



//дружественная функция для вывода информации о сотрудниках в виде таблицы
void printEmployeeTable(std::vector<Employee> employees)
{
    std::cout << std::left
              << std::setw(15) << "| ID | "
              << std::setw(18) << "Salary | "
              << std::setw(25) << "Date for getting job | "
              << std::setw(5) << "Type of job | " << std::endl;
    std::cout << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;

    for (int i = 0; i < employees.size(); ++i)
    {
        std::cout << std::left
                  << std::setw(15) << employees[i].getNumberOfEmployee()
                  << std::setw(18) << employees[i].getSalary()
                  << std::setw(0) << employees[i].date.getDay() << "/" << employees[i].date.getMonth() << "/" << employees[i].date.getYear();

        switchTypeProfession(employees[i].m_currentEmployee);
        std::cout << std::endl;
        std::cout << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
    }
}



//метод для записи объекта в файл
void Employee::writeToFile(std::ofstream& outputFile) const
{
    outputFile << numberOfEmployee << "\n";
    outputFile << salary << "\n";
    outputFile << m_currentEmployee << "\n";
    outputFile << date.getDay() << " " << date.getMonth() << " " << date.getYear() << "\n";
}



//метод для чтения данных в объект
void Employee::readFromFile(std::ifstream& inputFile)
{
    int employeeTypeValue, day, month, year;
    inputFile >> numberOfEmployee;
    inputFile >> salary;
    inputFile >> employeeTypeValue;
    m_currentEmployee = static_cast<employeeType>(employeeTypeValue);
    inputFile >> day >> month >> year;
    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    counter++;
}



//функция записи данных в файл
void writeTextFile(std::vector<Employee>& employees)
{
    std::string fileName;
    std::cout << "Введите имя файла - "; std::cin >> fileName;
    std::ofstream outputFile(fileName.c_str());
    if (!outputFile.is_open()) { std::cerr << "Не удалось открыть файл для записи" << std::endl; exit(EXIT_FAILURE);}
    outputFile << employees.size() << "\n";
    for (const Employee& employee : employees)
    {
        employee.writeToFile(outputFile);
    }

    outputFile.close();
}



//функция чтения данных из файла
std::vector<Employee> readTextFile()
{
    std::string fileName; std::cout << "Введите имя файла - "; std::cin >> fileName;
    std::vector<Employee> employees;
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open()) { std::cerr << "Не удалось открыть файл для чтения" << std::endl; exit(EXIT_FAILURE);}
    int n; inputFile >> n;
    Employee employee;
    for(int i = 0; i < n; i++)
    {
        employee.readFromFile(inputFile);
        employees.push_back(employee);
    }

    inputFile.close();
    return employees;
}



//свитч кейс для вывода названия профессии
void switchTypeProfession (employeeType employee)
{
    switch (employee)
    {
        case PROGRAMMER:
            std::cout << "\t\t\tProgrammer";
            break;
        case DOCTOR:
            std::cout << "\t\t\tDoctor";
            break;
        case BANKER:
            std::cout << "\t\t\tBanker";
            break;
        case LAWYER:
            std::cout << "\t\t\tLawyer";
            break;
        case TEACHER:
            std::cout << "\t\t\tTeacher";
            break;
        case PRIEST:
            std::cout << "\t\t\tPriest";
            break;
        default:
            std::cout << "\t\t\tНеизвестный";
            break;
    }
}













///////////////////////////////////////////Перегрузка операторов и функций//////////////////////////////////////////////

Employee operator+ (const Employee &person1, const Employee &person2)
{
    return Employee(person1.getSalary() + person2.getSalary());
}

bool operator& (const Employee &person1, const Employee &person2)
{
    if (person1.getTypeEmployee() == person2.getTypeEmployee())
        return true;
    return false;
}