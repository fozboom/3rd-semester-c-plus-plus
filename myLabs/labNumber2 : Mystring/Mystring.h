#ifndef UNTITLED_MYSTRING_H
#define UNTITLED_MYSTRING_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

class Mystring
{
private:
    char * str;
public:
    explicit Mystring(const char * buf = "");
    ~Mystring();
    Mystring& operator = (const Mystring &other);
    Mystring& operator += (const Mystring &other);

    const char * getStr()const{return str;}
    void print ();
};
bool operator == (const Mystring &object1, const Mystring &object2);
bool operator != (const Mystring &object1, const Mystring &object2);
Mystring operator+(const Mystring &object1, const Mystring &object2);


#endif //UNTITLED_MYSTRING_H
