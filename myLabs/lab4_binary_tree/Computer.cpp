#include "Computer.h"

Computer::~Computer()
{

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
    std::cout << "\nВведите кол-во оперативной памяти:";
    RAM = inputNumber(0, 64);
}

int Computer::getRAM() const
{
    return RAM;
}

void Computer::setStorageCapacity()
{
    std::cout << "\nВведите объем SSD:";
    storageCapacity = inputDouble(0.0, 2056.0);
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
    std::cout << "Введите цену:";
    price = inputDouble(0.0, 100000.0);
}

double Computer::getPrice() const
{
    return price;
}

void Computer::setWeight()
{
    std::cout << "Введите вес:";
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

void Computer::banner()
{
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << "brandName" << std::setw(SIZE/2)
                << "modelName" << std::setw(SIZE/2)
                << "RAM" << std::setw(SIZE/2)
                << "stCapacity" <<  std::setw(SIZE/2)
                << "opSystem" <<  std::setw(SIZE/2)
                << "price" << std::setw(SIZE/2)
                << "weight";
}



computerType Computer::getType()
{
    if (typeid(*this) == typeid(Desktop))
        return tDesktop;
    else
        std::cout << "Неправильный тип работника"; exit(EXIT_FAILURE);
}

bool Desktop::operator==(const Desktop& other) const {
    return this->getPrice() == other.getPrice();
}

bool Desktop::operator!=(const Desktop& other) const {
    return this->getPrice() != other.getPrice();
}

bool Desktop::operator>=(const Desktop& other) const {
    return this->getPrice() >= other.getPrice();
}

bool Desktop::operator<=(const Desktop& other) const {
    return this->getPrice() <= other.getPrice();
}

bool Desktop::operator>(const Desktop& other) const {
    return this->getPrice() > other.getPrice();
}

bool Desktop::operator<(const Desktop& other) const {
    return this->getPrice() < other.getPrice();
}

std::ostream &operator << (std::ostream &os, Desktop &desktop)
{
    desktop.print();
    return os;
}

std::ofstream &operator << (std::ofstream &os, Desktop &desktop)
{
    os.write(reinterpret_cast<const char*>(&desktop), sizeof(desktop));
    return os;
}


std::ifstream &operator << (std::ifstream &is, Desktop &desktop)
{
    is.read(reinterpret_cast<char*>(&desktop), sizeof(desktop));
    return is;
}

