#ifndef UNTITLED_HEADER_H
#define UNTITLED_HEADER_H
#include "Computer.h"
#include <iostream>
#include <ios>
#include <iomanip>
#include <typeinfo>

int isNumber(const std::string& str);
int inputNumber (int start, int finish);
double inputDouble (double start, double finish);


int myStrlen(const char *str);                                                          //функция подсчета длины строки
[[maybe_unused]] int myStrcmp (const char * str1, const char * str2);                   //функция сравнения строк
void myStrcpy (char ** str1, const char * str2);                                        //функция копирования строки
void myStrcat (char ** str1, const char * str2);                                        //функция добавления строки в конец текущей

#endif //UNTITLED_HEADER_H
