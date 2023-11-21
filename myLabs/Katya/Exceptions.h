#ifndef UNTITLED_EXCEPTIONS_H
#define UNTITLED_EXCEPTIONS_H

#include "cstring"
#include <iostream>

int inputNumber();

class Exceptions: public std::exception
{
protected:
    std::string message;
public:
    Exceptions() = default;

    [[nodiscard]] const char* what() const noexcept override{return message.c_str();}

};

class ExceptionInputNumber: public Exceptions
{
public:
    explicit ExceptionInputNumber(std::string mes)
    {
        message = std::move(mes);
    }
    ExceptionInputNumber() = delete;

};

class ExceptionInputAge: public Exceptions
{
public:
    explicit ExceptionInputAge(std::string mes)
    {
        message = std::move(mes);
    }
    ExceptionInputAge() = delete;

};

class ExceptionInputData: public Exceptions
{
public:
    explicit ExceptionInputData(std::string mes)
    {
        message = std::move(mes);
    }
    ExceptionInputData() = delete;

};


#endif //UNTITLED_EXCEPTIONS_H
