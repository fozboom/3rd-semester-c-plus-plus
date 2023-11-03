cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(LabNumber1
        "myLabs/LabNumber1/mainLab1.cpp"
        "myLabs/LabNumber1/employee.cpp"
        "myLabs/LabNumber1/employee.h"
        "myLabs/labNumber2 : Mystring/Mystring.h"
        "myLabs/labNumber2 : Mystring/Mystring.cpp" Lection/main.cpp)


add_executable(LabNumber2
        "myLabs/labNumber2 : Mystring/mainLab2.cpp"
        "myLabs/labNumber2 : Mystring/Mystring.h"
        "myLabs/labNumber2 : Mystring/Mystring.cpp")

add_executable(LabNumber3
        "myLabs/labNumber3 : inheritance and virtual/main.cpp"
        "myLabs/labNumber3 : inheritance and virtual/Computer.cpp"
        "myLabs/labNumber3 : inheritance and virtual/Computer.h"
        "myLabs/labNumber3 : inheritance and virtual/Desktop.cpp"
        "myLabs/labNumber3 : inheritance and virtual/PortableDevice.cpp"
        "myLabs/labNumber3 : inheritance and virtual/header.h"
        "myLabs/labNumber3 : inheritance and virtual/functions.cpp"
        "myLabs/labNumber3 : inheritance and virtual/Monoblock.cpp"
        "myLabs/labNumber3 : inheritance and virtual/Monoblock.cpp"
        "myLabs/labNumber3 : inheritance and virtual/TabletComputer.cpp"
        "myLabs/labNumber3 : inheritance and virtual/Laptop.cpp")

add_executable(LeetCode
        "LeetCode/mainLeetCode.cpp"
        "LeetCode/functionsLeetCode.cpp"
        "LeetCode/headerLeetCode.h")

add_executable(BinaryTree
        myLabs/labNumber4BinaryTree/Tree.cpp
        myLabs/labNumber4BinaryTree/Tree.h
        myLabs/labNumber4BinaryTree/main.cpp myLabs/labNumber4BinaryTree/main.cpp)


