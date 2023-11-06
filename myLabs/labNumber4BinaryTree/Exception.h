#ifndef UNTITLED_EXCEPTION_H
#define UNTITLED_EXCEPTION_H
#include "cstring"
#include <iostream>

int inputNumber();

class Exception:public std::exception
{
private:
    int code;
    char message[80]{};
public:
    Exception();
    Exception(int x, const char* mes);
    void showErrorMessage();
};

class ExceptionInputNumber : public Exception {
public:
    ExceptionInputNumber(int x, const char* m): Exception(x, m){}
};

class ExceptionFile : public Exception {
public:
    ExceptionFile(int x, const char* m) : Exception(x, m) {}
};




#endif //UNTITLED_EXCEPTION_H
