#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <vector>

const int countEmployeeType = 7;

enum employeeType{
    UNEMPLOYED,
    PROGRAMMER,
    DOCTOR,
    BANKER,
    LAWYER,                 //юрист
    TEACHER,
    PRIEST
};



class Employee
{
private:
    int numberOfEmployee;
    static int counter;
    float salary;
    enum employeeType m_currentEmployee;

    class Date
    {
    public:
        int m_day;
        int m_month;
        int m_year;
        Date (): m_day(0), m_month(0), m_year(0)
        {}
        Date (int day, int month, int year);

        void setDay (int);
        void setMonth(int);
        void setYear(int);

        [[nodiscard]] int getDay() const{return m_day;}
        [[nodiscard]] int getMonth() const{return m_month;}
        [[nodiscard]] int getYear() const {return m_year;}

    } date;

public:
    Employee (): numberOfEmployee(0), salary(0.0), date(), m_currentEmployee(UNEMPLOYED) {}
    Employee(float salary, Date date, employeeType currentEmployee);
    void getEmployee ();
    void putEmployee ();
    [[nodiscard]] int getNumberOfEmployee() const {return numberOfEmployee;}
    [[nodiscard]] float getSalary() const {return salary;}
    friend void printEmployeeTable(std::vector<Employee> employees);
};

template <typename T> T inputNumber (T a, T b);
int checkDay(int day);
int checkMonth(int month);
int checkYear(int year);

#endif //UNTITLED_EMPLOYEE_H
