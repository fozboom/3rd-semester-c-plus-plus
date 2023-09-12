#include "employee.h"

void switchTypeProfession (employeeType employee)
{
    switch (employee)
    {
        case PROGRAMMER:
            std::cout << "\t\tProgrammer";
            break;
        case DOCTOR:
            std::cout << "\t\t\tDoctor";
            break;
        case BANKER:
            std::cout << "\t\t\ttBanker";
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
            std::cout << "Неизвестный";
            break;
    }
}

Employee::Date::Date(int day, int month, int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

Employee::Employee(int numberOfEmployee, float salary, Date date, employeeType currentEmployee)
{
    numberOfEmployee = numberOfEmployee;
    salary = salary;
    date = date;
    currentEmployee = currentEmployee;
}

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



void Employee::getEmployee(int numberOfEmp)
{
    std::cout << "Введите число даты\n";
    date.setDay(checkDay(inputNumber<int>()));
    std::cout << "Введите месяц\n";
    date.setMonth(checkMonth(inputNumber<int>()));
    std::cout << "Введите год\n";
    date.setYear(checkYear((inputNumber<int>())));

    std::cout << "Введите заработную плату\n";
    salary = inputNumber<float>();
    std::cout << "Введите тип профессии\n";
    std::cout << "\n1 - программист" << "\n2 - врач" << "\n3 - банкир" << "\n4 - юрист" << "\n5 - учитель" << "\n6 - священник";
    int typeProfession = inputNumber<int>();
    m_currentEmployee = static_cast<employeeType>(typeProfession);

    numberOfEmployee = numberOfEmp;
}

void Employee::putEmployee(int numOfEmployee)
{
    std::cout << "Информация о сотруднике №" << numOfEmployee << ":\n";
    std::cout << "Дата приема на работу: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << std::endl;
    std::cout << "Заработная плата: " << salary << " рублей";
    std::cout << "Должность: ";
    switchTypeProfession(m_currentEmployee);
}


template <typename T>
T inputNumber ()
{
    while (true)
    {
        T x;
        std::cin >> x;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
    }
}

int checkDay(int day)
{
    while(day < 1 || day > 31)
    {
        std::cout << "Ошибка, день должен быть в границах от 1 до 31, введите день: ";
        day = inputNumber<int>();
    }
    return day;
}

int checkMonth(int month)
{
    while(month < 1 || month > 12)
    {
        std::cout << "Ошибка, месяц должен быть в границах от 1 до 12, введите месяц: ";
        month = inputNumber<int>();
    }
    return month;
}

int checkYear(int year)
{
    while(year < 1000 || year > 3000)
    {
        std::cout << "Ошибка, год должен быть в границах от 1000 до 3000, введите год: ";
        year = inputNumber<int>();
    }
    return year;
}



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
