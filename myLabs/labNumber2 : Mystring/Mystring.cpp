#include "Mystring.h"

int myStrlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

[[maybe_unused]] int myStrcmp (const char * str1, const char * str2)
{
    while (*str1 && *str2 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}


void myStrcpy (char ** str1, const char * str2)
{
    if (*str1 != nullptr)
        delete [] *str1;
    int size = myStrlen(str2) + 1;
    *str1 = new char [size];
    int i = 0;
    while (i < myStrlen(str2))
    {
        *(*str1 + i) = str2[i];
        i++;
    }
    *(*str1 + i) = '\0';
}

void myStrcat (char ** str1, const char * str2)
{
    int size1 = myStrlen(*str1), size2 = myStrlen(str2), size = size1 + size2 + 1;
    char *buf = nullptr;
    myStrcpy(&buf, *str1);
    if (*str1 != nullptr)
        delete [] *str1;
    *str1 = new char [size];
    int i = 0;
    for (int j = 0; j < size1; j++)
        *(*str1 + i++) = buf[j];
    for (int j = 0; j < size2; j++)
        *(*str1 + i++) = str2[j];
    *(*str1 + i) = '\0';
}

//конструктор с одним параметром и аргументом по умолчанию
Mystring::Mystring(const char *buf)
{
    if (buf != nullptr)
    {
        str = new char [myStrlen(buf) + 1];
        myStrcpy(&this->str, buf);
    }
}

//деструктор
Mystring::~Mystring()
{
    std::cout << "\nРаботает деструктор\n";
    delete[] str;
}

Mystring& Mystring::operator=(const Mystring &other)
{
    delete[] this->str;
    this-> str = new char [myStrlen(other.str) + 1];
    myStrcpy(&this->str, other.str);
    return *this;
}

Mystring operator+(const Mystring &object1, const Mystring &object2)
{
    char* result = nullptr;
    myStrcpy(&result, object1.getStr());
    myStrcat(&result, object2.getStr());
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


std::ostream& operator<< (std::ostream& out, const Mystring &object)
{
    out << object.getStr();
    return out;
}


//метод для вывода строки на экран
void Mystring::print()
{
//    for (int i = 0; this->str[i] != '\0'; i++)
//        std::cout << str[i];
    std::cout << str << std::endl;
}

char& Mystring::operator[](int index)
{
    return this->str[index];
}

void Mystring::operator()(int first, int last)
{
    for (int i = first; i <= last; i++)
    {
        std::cout << str[i];
    }
}

Mystring::Mystring(const Mystring &object)
{
    this->str = new char [myStrlen(object.getStr())];
    myStrcpy(&this->str, object.getStr());
}

void Mystring::inputStr()
{
    const int SIZE = 80;
    char* buf = new char [SIZE];
    std::cout << "Введите строку - ";
    std::cin >> buf;
    myStrcpy(&this->str, buf);
}

void Mystring::reverse(int i, int j)
{
    if (i >= j)
        return;
    else
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

void Mystring::reverse()
{
    int i = 0, j = myStrlen(this->str) - 1;
    while (i < j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

void Mystring::toLower()
{
    for(int i = 0; i < myStrlen(str); i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] -= ('A' - 'a');
        }
    }
}

void Mystring::toCaps()
{
    for(int i = 0; i < myStrlen(str); i++)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            str[i] += ('A' - 'a');
        }
    }
}


