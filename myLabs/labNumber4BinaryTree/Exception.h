#ifndef UNTITLED_EXCEPTION_H
#define UNTITLED_EXCEPTION_H
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

class ExceptionFile: public Exceptions
{
public:
    explicit ExceptionFile(std::string mes)
    {
        message = std::move(mes);
    }
    ExceptionFile() = delete;

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




#endif //UNTITLED_EXCEPTION_H
