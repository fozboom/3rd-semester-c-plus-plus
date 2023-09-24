#include "Mystring.h"


int main ()
{
    Mystring str1("Hello"), str2("Hello"), str3;
    if (str1 == str2)
        std::cout << "true";
    else
        std::cout << "false";
    return 0;
}

