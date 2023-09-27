#ifndef UNTITLED_MYSTRING_H
#define UNTITLED_MYSTRING_H
#include <iostream>
#include <iomanip>


class Mystring
{
private:
    char * str;
public:
    explicit Mystring(const char * buf = "");                                           //конструктор с аргументом по умолчанию
    Mystring (const Mystring& object);                                                  //конструктор копирования
    ~Mystring();                                                                        //деструктор
    [[nodiscard]] const char * getStr()const{return str;}                               //гетер

    Mystring& operator = (const Mystring &other);
    Mystring& operator += (const Mystring &other);
    char & operator[](int index);
    char* operator()(int first, int last);

    void inputStr();                                                                    //ввод строки
    void print ();                                                                      //вывод строки
    void reverse(int i , int j);                                                        //реверс части строки
    void reverse();                                                                     //реверс всей строки
    void toLower();                                                                     //привести к нижнему регистру
    void toCaps();                                                                      //привести к верхнему регистру
};

bool operator == (const Mystring &object1, const Mystring &object2);
bool operator != (const Mystring &object1, const Mystring &object2);
Mystring operator+(const Mystring &object1, const Mystring &object2);
std::ostream& operator<< (std::ostream& out, const Mystring &object);
template <typename T> T inputNumber (T a, T b);                                         //ввод числа с проверкой
int myStrlen(const char *str);                                                          //функция подсчета длины строки
[[maybe_unused]] int myStrcmp (const char * str1, const char * str2);                   //функция сравнения строк
void myStrcpy (char ** str1, const char * str2);                                        //функция копирования строки
void myStrcat (char ** str1, const char * str2);                                        //функция добавления строки в конец текущей



#endif //UNTITLED_MYSTRING_H
