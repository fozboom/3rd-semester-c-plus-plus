#ifndef UNTITLED12_FUNCTIONS_H
#define UNTITLED12_FUNCTIONS_H
#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include "Exceptions.h"

#define SIZE 100

class Man {
public:
    Man();
    ~Man();
    virtual const char* getFName() = 0;
    virtual const char* getSName() = 0;
    virtual int getAge() = 0;
    virtual void setAge(int age) = 0;
};

class Teacher : virtual public Man {
private:
    char course[SIZE];
    char ManFirstName[SIZE];
    char ManSecondName[SIZE];
    int age;
    int experience;
    int year;
    int month;
    int day;
public:
    Teacher(const char* course, const char* firstName, const char* secondName, int age, int experience, int year, int month, int day);

    ~Teacher();

    const char* getFName() override;

    const char* getSName() override;

    int getAge() override;

    void setAge(int newAge) override;

    virtual int getExperience();

    const char* getName();

};

class UnionMember : virtual public Man {
private:
    char post[SIZE];
    char ManFirstName[SIZE];
    char ManSecondName[SIZE];
    int age;
public:
    UnionMember(const char* post, const char* firstName, const char* secondName, int age);

    ~UnionMember();

    const char* getFName() override;

    const char* getSName() override;

    int getAge() override;

    void setAge(int newAge) override;

    virtual const char* getPost();
};

class UnionMemberAndTeacher : public Teacher, public UnionMember {
private:
    char interests[SIZE];
public:
    UnionMemberAndTeacher(const char* interests, const char* course, const char* post, const char* firstName,
                          const char* secondName, int age, int experience, int year, int month, int day);

    ~UnionMemberAndTeacher();

    const char* getFName() override;

    const char* getSName() override;

    int getAge() override;

    void setAge(int newAge) override;

    int getExperience() override;

    virtual const char* getInterest();
};

void task1();

void task2();

void task3();

void task4();

bool isValidNum(int& num);

#endif //UNTITLED12_FUNCTIONS_H
