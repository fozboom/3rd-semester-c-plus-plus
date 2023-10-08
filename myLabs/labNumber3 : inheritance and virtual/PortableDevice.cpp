#include "Computer.h"

// Конструктор по умолчанию
PortableDevice::PortableDevice(): Computer()
{
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

void PortableDevice::inputPortableDeviceData()
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
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << "brandName" << std::setw(SIZE/2)
                << "modelName" << std::setw(SIZE/2)
                << "RAM" << std::setw(SIZE/2)
                << "stCapacity" <<  std::setw(SIZE/2)
                << "opSystem" <<  std::setw(SIZE/2)
                << "price" << std::setw(SIZE/2)
                << "weight" << std::setw(SIZE/2)
                << "batteryPower" << std::setw(SIZE/2)
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




