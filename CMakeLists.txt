cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(LabNumber1
        "myLabs/LabNumber1/mainLab1.cpp"
        "myLabs/LabNumber1/employee.cpp"
        "myLabs/LabNumber1/employee.h"
        "myLabs/labNumber2 : Mystring/Mystring.h"
        "myLabs/labNumber2 : Mystring/Mystring.cpp")


add_executable(LabNumber2
        "myLabs/labNumber2 : Mystring/mainLab2.cpp"
        "myLabs/labNumber2 : Mystring/Mystring.h"
        "myLabs/labNumber2 : Mystring/Mystring.cpp")

add_executable(LeetCode
        "LeetCode/mainLeetCode.cpp"
        "LeetCode/functionsLeetCode.cpp"
        "LeetCode/headerLeetCode.h")
