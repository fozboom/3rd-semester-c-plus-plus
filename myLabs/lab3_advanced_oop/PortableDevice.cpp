#include "Computer.h"

// Конструктор по умолчанию
PortableDevice::PortableDevice(): Computer()
{
    std::cout << "\nКонструктор класса PortableDevice";
    batteryPower = 0;
    screenSize = 0.0;
    hasWiFi = false;
    hasBluetooth = false;
}

PortableDevice::PortableDevice(const PortableDevice& other) : Computer(other)
{
    this->batteryPower = other.batteryPower;
    this->screenSize = other.screenSize;
    this->hasWiFi = other.hasWiFi;
    this->hasBluetooth = other.hasBluetooth;
}

void PortableDevice::setBatteryPower()
{
    std::cout << "\nВведите мощность батареи:";
    batteryPower = inputNumber(0, 1000);
}

int PortableDevice::getBatteryPower() const
{
    return batteryPower;
}

void PortableDevice::setScreenSize()
{
    std::cout << "\nВведите размер экрана (дюймы):";
    screenSize = inputDouble(0.0, 30.0);
}

double PortableDevice::getScreenSize() const
{
    return screenSize;
}

void PortableDevice::setHasWiFi()
{
    std::cout << "\nЕсть ли Wi-Fi? (1 - Да, 0 - Нет):";
    int choice = inputNumber(0, 1);
    hasWiFi = (choice == 1);
}

bool PortableDevice::getHasWiFi() const
{
    return hasWiFi;
}

void PortableDevice::setHasBluetooth()
{
    std::cout << "\nЕсть ли Bluetooth? (1 - Да, 0 - Нет):";
    int choice = inputNumber(0, 1);
    hasBluetooth = (choice == 1);
}

bool PortableDevice::getHasBluetooth() const
{
    return hasBluetooth;
}

void PortableDevice::inputData()
{
    Computer::inputData();
    setBatteryPower();
    setScreenSize();
    setHasWiFi();
    setHasBluetooth();
}

void PortableDevice::print()
{
    std::cout << "\033[31mPORTABLE DEVICE\033[0m" << std::endl;
    banner();
    std::cout.width(SIZE/2);
    std::cout   << "batteryPower" << std::setw(SIZE/2)
                << "screenSize" << std::setw(SIZE/2)
                << "hasWifi" << std::setw(SIZE/2)
                << "hasBluetooth" << std::endl;
    Computer::print();
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << batteryPower << std::setw(SIZE/2)
                << screenSize << std::setw(SIZE/2)
                << hasWiFi << std::setw(SIZE/2)
                << hasBluetooth << std::endl;
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
}

PortableDevice::~PortableDevice()
{
    std::cout << "\nДеструктор класса PortableDevice";
}

//PortableDevice::PortableDevice(PortableDevice &&other) noexcept: Computer(std::move(other))
//{
//    this->batteryPower = other.batteryPower;
//    this->screenSize = other.screenSize;
//    this->hasWiFi = other.hasWiFi;
//    this->hasBluetooth = other.hasBluetooth;
//
//    other.batteryPower = 0;
//    other.screenSize = 0.0;
//    other.hasWiFi = false;
//    other.hasBluetooth = false;
//}
//
//PortableDevice &PortableDevice::operator=(PortableDevice &&other) noexcept
//{
//    if(this != &other)
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




