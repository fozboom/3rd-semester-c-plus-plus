#include "Computer.h"

void Computer::setBrandName()
{
    std::cout << "\nВведите название бренда - ";
    std::cin.getline(brandName, SIZE, '\n');
}

char* Computer::getBrandName()
{
    return this->brandName;
}

void Computer::setModelName()
{
    std::cout << "\nВведите название модели - ";
    std::cin.getline(brandName, SIZE, '\n');
}

char *Computer::getModelName()
{
    return this->modelName;
}

void Computer::setRAM()
{
    std::cout << "\nВведите кол-во оперативной памяти - ";
    RAM = inputNumber(0, 64);
}

int Computer::getRAM() const
{
    return RAM;
}

void Computer::setStorageCapacity()
{
    storageCapacity = inputDouble(0.0, 256.0);
}

double Computer::getStorageCapacity() const
{
    return storageCapacity;
}

void Computer::setSystem()
{
    std::cout << "\nВыберите тип операционной системы:"
              << "\n1 - Windows"
              << "\n2 - MasOS"
              << "\n3 - Linux"
              << "\n4 - Android"
              << "\n5 - IOS";
    int choice = inputNumber(0, 5);
    switch (choice)
    {
        case 1:
            system = Windows;
            break;
        case 2:
            system = MacOS;
            break;
        case 3:
            system = Linux;
            break;
        case 4:
            system = Android;
            break;
        case 5:
            system = IOS;
            break;
        default:
            std::cout << "\nОшибка в switch case";
            break;
    }
}

operatingSystem Computer::getSystem()
{
    return system;
}

void Computer::setPrice()
{
    std::cout << "Введите цену - ";
    price = inputDouble(0.0, 100000.0);
}

double Computer::getPrice() const
{
    return price;
}

void Computer::setWeight()
{
    std::cout << "Введите вес - ";
    weight = inputDouble(0.0, 100000.0);
}

double Computer::getWeight() const
{
    return weight;
}

Computer::Computer()
{
    RAM = 0;
    storageCapacity = 0.0;
    system = noname;
    price = 0.0;
    weight = 0.0;
}

Computer::Computer(const Computer &other)
{
    this->RAM = other.RAM;
    this->storageCapacity = other.storageCapacity;
    this->system = other.system;
    this->price = other.price;
    this->weight = other.weight;
}
