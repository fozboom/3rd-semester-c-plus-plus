#include "Mystring.h"

[[maybe_unused]] int myStrcmp (const char * str1, const char * str2)
{
    while (*str1 && *str2 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

//конструктор с одним параметром и аргументом по умолчанию
Mystring::Mystring(const char *buf)
{
    if (buf != nullptr)
    {
        str = new char [strlen(buf) + 1];
        strcpy(str, buf);
    }
}

//деструктор
Mystring::~Mystring()
{
    std::cout << "\nРаботает диструктор\n";
    delete[] str;
}

Mystring& Mystring::operator=(const Mystring &other)
{
    delete[] this->str;
    this-> str = new char [strlen(other.str) + 1];
    strcpy(this->str, other.str);
    return *this;
}

Mystring operator+(const Mystring &object1, const Mystring &object2)
{
    int size1 = (int)strlen(object1.getStr()), size2 = (int)strlen(object2.getStr()), i = 0;
    char * result = new char [size1 + size2 + 1];

    for(int j = 0; j < size1; j++)
        result[i++] = object1.getStr()[j];
    for(int j = 0; j < size2; j++)
        result[i++] = object2.getStr()[j];
    result[i] = '\0';

    Mystring Result(result);

    delete[] result;

    return Result;
}


Mystring& Mystring::operator+=(const Mystring &other)
{
   *this = *this + other;
   return *this;
}



bool operator == (const Mystring &object1,const Mystring &object2)
{
    return (myStrcmp(object1.getStr(), object2.getStr()) == 0);
}

bool operator != (const Mystring &object1,const Mystring &object2)
{
    return (myStrcmp(object1.getStr(), object2.getStr()) != 0);
}


//метод для вывода строки на экран
void Mystring::print()
{
//    for (int i = 0; this->str[i] != '\0'; i++)
//        std::cout << str[i];
    std::cout << str << std::endl;
}


