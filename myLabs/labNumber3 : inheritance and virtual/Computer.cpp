#include "Computer.h"

Computer::~Computer()
{
    std::cout << "\nДеструктор класса Computer";
}

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
    std::cin.getline(modelName, SIZE, '\n');
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
    system = choiceSystem();

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
    strcpy(this->brandName, other.brandName);
    strcpy(this->modelName, other.modelName);
    this->RAM = other.RAM;
    this->storageCapacity = other.storageCapacity;
    this->system = other.system;
    this->price = other.price;
    this->weight = other.weight;
}

void Computer::inputData()
{
    setBrandName();
    setModelName();
    setRAM();
    setStorageCapacity();
    setSystem();
    setPrice();
    setWeight();
}

void Computer::print()
{

    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << brandName << std::setw(SIZE/2)
                << modelName << std::setw(SIZE/2)
                << RAM << std::setw(SIZE/2)
                << storageCapacity;
    printOperatingSystem(system);
    std::cout.width(SIZE/2);
    std::cout   << price << std::setw(SIZE/2)
                << weight;
}
