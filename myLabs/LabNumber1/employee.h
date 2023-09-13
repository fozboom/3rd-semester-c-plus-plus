#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

const int countEmployeeType = 7;                                                                                        //кол-во элементов в перечислении


enum employeeType{                                                                                                      //перечисление с типом профессий
    UNEMPLOYED,
    PROGRAMMER,
    DOCTOR,
    BANKER,
    LAWYER,
    TEACHER,
    PRIEST
};

class Employee
{
private:
    int numberOfEmployee;                                               //номер сотрудника (его ID)
    static int counter;                                                 //счетчик кол-ва работников
    float salary;                                                       //заработная плата
    enum employeeType m_currentEmployee;                                //тип профессии

    class Date                                                          //вложенный класс для хранения даты приема на работу
    {
    public:
        int m_day;
        int m_month;
        int m_year;
        Date (): m_day(0), m_month(0), m_year(0) {}                     //конструктор для инициализации нулем
        Date (int day, int month, int year);                            //конструктор с параметрами

        void setDay (int);                                              //методы для установления даты
        void setMonth(int);
        void setYear(int);

        [[nodiscard]] int getDay() const{return m_day;}                 //методы для получения даты
        [[nodiscard]] int getMonth() const{return m_month;}
        [[nodiscard]] int getYear() const {return m_year;}

    } date;

public:
    Employee (): numberOfEmployee(0), salary(0.0), date(), m_currentEmployee(UNEMPLOYED) {}                             //конструктор без параметров
    Employee(float salary, Date date, employeeType currentEmployee);                                                    //конструктор с параметрами
    void getEmployee ();                                                                                                //методы для получения типа профессии
    void putEmployee ();                                                                                                //методы для установления типа профессии
    void readFromFile(std::ifstream& inputFile);                                                                        //метод для чтения данных из файла
    void writeToFile(std::ofstream& outputFile) const;                                                                  //метод для записи данных в файл


    [[nodiscard]] int getNumberOfEmployee() const {return numberOfEmployee;}                                            //узнать номер сотрудника
    [[nodiscard]] float getSalary() const {return salary;}                                                              //узнать заработную плату
    friend void printEmployeeTable(std::vector<Employee> employees);                                                    //вывести данные в виде таблицы
};
int Employee::counter = 0;                                                                                              //статическая переменная - счетчик кол-ва работников

template <typename T> T inputNumber (T a, T b);                                                                         //шаблонная функция ввода числа
void writeTextFile(std::vector<Employee>& employees);                                                                   //функция записи вектора объектов в файл
std::vector<Employee> readTextFile();                                                                                   //функция чтения данных из файла в вектор
void switchTypeProfession (employeeType employee);                                                                      //функция для выбора типа профессии
#endif //UNTITLED_EMPLOYEE_H
