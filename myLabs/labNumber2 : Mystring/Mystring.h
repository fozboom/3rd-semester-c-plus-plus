#ifndef UNTITLED_MYSTRING_H
#define UNTITLED_MYSTRING_H
#include <iostream>
#include <iomanip>


class Mystring
{
private:
    char * str;
public:
    explicit Mystring(const char * buf = "");
    Mystring (const Mystring& object);
    ~Mystring();
    [[nodiscard]] const char * getStr()const{return str;}

    Mystring& operator = (const Mystring &other);
    Mystring& operator += (const Mystring &other);
    char & operator[](int index);
    void operator()(int first, int last);

    void inputStr();
    void print ();
    void reverse(int i , int j);
    void reverse();
    void toLower();
    void toCaps();
};
bool operator == (const Mystring &object1, const Mystring &object2);
bool operator != (const Mystring &object1, const Mystring &object2);
Mystring operator+(const Mystring &object1, const Mystring &object2);
std::ostream& operator<< (std::ostream& out, const Mystring &object);




#endif //UNTITLED_MYSTRING_H
