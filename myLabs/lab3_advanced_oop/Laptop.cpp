#include "Computer.h"

Laptop::Laptop()
{
    std::cout << "\nКонструктор класса Laptop";
    keyCount = 0;
    portCount = 0;
    keyboardBacklight = false;
    touchpadSize = 0.0;
}

Laptop::Laptop(const Laptop& other) : PortableDevice(other)
{
    this->keyCount = other.keyCount;
    this->portCount = other.portCount;
    this->keyboardBacklight = other.keyboardBacklight;
    this->touchpadSize = other.touchpadSize;
}

void Laptop::setKeyCount()
{
    std::cout << "\nВведите количество клавиш:";
    keyCount = inputNumber(0, 200);
}

int Laptop::getKeyCount() const
{
    return keyCount;
}

void Laptop::setPortCount()
{
    std::cout << "\nВведите количество портов:";
    portCount = inputNumber(0, 10);
}

int Laptop::getPortCount() const
{
    return portCount;
}

void Laptop::setKeyboardBacklight()
{
    std::cout << "\nЕсть ли подсветка клавиатуры? (1 - Да, 0 - Нет):";
    int choice = inputNumber(0, 1);
    keyboardBacklight = (choice == 1);
}

bool Laptop::getKeyboardBacklight() const
{
    return keyboardBacklight;
}

void Laptop::setTouchpadSize()
{
    std::cout << "\nВведите размер тачпада (в дюймах):";
    touchpadSize = inputDouble(0.0, 10.0);
}

double Laptop::getTouchpadSize() const
{
    return touchpadSize;
}

void Laptop::inputData()
{
    PortableDevice::inputData();
    setKeyCount();
    setPortCount();
    setKeyboardBacklight();
    setTouchpadSize();
}

void Laptop::print()
{
    std::cout << "\033[31mLAPTOP\033[0m" << std::endl;
    banner();
    std::cout.width(SIZE/2);
    std::cout   << "batteryPower" << std::setw(SIZE/2)
                << "screenSize" << std::setw(SIZE/2)
                << "hasWifi" << std::setw(SIZE/2)
                << "hasBluetooth" << std::setw(SIZE/2)
                << "keyCount" << std::setw(SIZE/2)
                << "portCount" << std::setw(SIZE/2)
                << "keyBlLight" << std::setw(SIZE/2)
                << "touchpadSize" << std::endl;
    Computer::print(); // NOLINT(bugprone-parent-virtual-call)
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << batteryPower << std::setw(SIZE/2)
                << screenSize << std::setw(SIZE/2)
                << hasWiFi << std::setw(SIZE/2)
                << hasBluetooth << std::setw(SIZE/2)
                << keyCount << std::setw(SIZE/2)
                << portCount << std::setw(SIZE/2)
                << keyboardBacklight << std::setw(SIZE/2)
                << touchpadSize << std::endl;
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
}

Laptop::~Laptop()
{
    std::cout << "\nДеструктор класса Laptop";
}

//Laptop::Laptop(Laptop &&other) noexcept: PortableDevice(std::move(other))
//{
//    this->keyCount = other.keyCount;
//    this->portCount = other.portCount;
//    this->keyboardBacklight = other.keyboardBacklight;
//    this->touchpadSize = other.touchpadSize;
//
//    other.keyCount = 0;
//    other.portCount = 0;
//    other.keyboardBacklight = false;
//    other.touchpadSize = 0.0;
//
//}
//
//Laptop &Laptop::operator=(Laptop &&other) noexcept
//{
//    if (this != &other)
//    {
//        strcpy(this->brandName, other.brandName);
//        strcpy(this->modelName, other.modelName);
//        this->RAM = other.RAM;
//        this->storageCapacity = other.storageCapacity;
//        this->system = other.system;
//        this->price = other.price;
//        this->weight = other.weight;
//        this->batteryPower = other.batteryPower;
//        this->screenSize = other.screenSize;
//        this->hasWiFi = other.hasWiFi;
//        this->hasBluetooth = other.hasBluetooth;
//
//
//
//        strcpy(other.brandName, "");
//        strcpy(other.modelName, "");
//        other.RAM = 0;
//        other.storageCapacity = 0.0;
//        other.system = noname;
//        other.price = 0.0;
//        other.weight = 0.0;
//        other.batteryPower = 0;
//        other.screenSize = 0.0;
//        other.hasWiFi = false;
//        other.hasBluetooth = false;
//    }
//    return *this;
//}
