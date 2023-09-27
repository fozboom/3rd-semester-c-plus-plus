#include "Mystring.h"

//вычисление длины строки
int myStrlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

//функция сравнения строк
[[maybe_unused]] int myStrcmp (const char * str1, const char * str2)
{
    while (*str1 && *str2 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

//функция копирования строки
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

//функция добавления строки в конец текущей
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

//перегрузка оператора =
Mystring& Mystring::operator=(const Mystring &other)
{
    delete[] this->str;
    this-> str = new char [myStrlen(other.str) + 1];
    myStrcpy(&this->str, other.str);
    return *this;
}

//перегрузка оператора +
Mystring operator+(const Mystring &object1, const Mystring &object2)
{
    char* result = nullptr;
    myStrcpy(&result, object1.getStr());
    myStrcat(&result, object2.getStr());
    Mystring Result(result);
    delete[] result;
    return Result;
}

//перегрузка оператора +=
Mystring& Mystring::operator+=(const Mystring &other)
{
   *this = *this + other;
   return *this;
}

//перегрузка оператора ==
bool operator == (const Mystring &object1,const Mystring &object2)
{
    return (myStrcmp(object1.getStr(), object2.getStr()) == 0);
}

//перегрузка оператора !=
bool operator != (const Mystring &object1,const Mystring &object2)
{
    return (myStrcmp(object1.getStr(), object2.getStr()) != 0);
}

//перегрузка оператора <<
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

//перегрузка оператора []
char& Mystring::operator[](int index)
{
    return this->str[index];
}

//перегрузка оператора ()
char* Mystring::operator()(int first, int last)
{
    char *result = new char[last - first + 2];
    int j = 0;
    for (int i = first; i <= last; i++)
    {
        result[j++] = str[i];
        std::cout << str[i];
    }
    return result;
}

//конструктор копирования
Mystring::Mystring(const Mystring &object)
{
    this->str = new char [myStrlen(object.getStr())];
    myStrcpy(&this->str, object.getStr());
}

//метод ввода строки
void Mystring::inputStr()
{
    const int SIZE = 80;
    char* buf = new char [SIZE];
    std::cout << "Введите строку - " << std::endl;
    rewind(stdin);
    std::cin.getline(buf, SIZE);
    myStrcpy(&this->str, buf);
}

//метод для реверса части строки
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

//метод для реверса всей строки
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

//метод для приведения всех символов к нижнему регистру
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

//метод для приведения всех символов к верхнему регистру
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

//шаблонная функция для ввода числа с проверкой
template <typename T>
T inputNumber (T a, T b)
{
    while (true)
    {
        T x;
        std::cin >> x;
        if (std::cin.fail() || x < a || x > b)                                                                          //если предыдущее извлечение не удалось
        {
            std::cout << "Ошибка ввода числа\n";
            std::cin.clear();                                                                                           //возвращаем в нормальный режим
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                                 //очистка всех символов до \n
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
    }
}

