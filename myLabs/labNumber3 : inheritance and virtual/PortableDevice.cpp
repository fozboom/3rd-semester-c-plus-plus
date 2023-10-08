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
    inputComputerData();
    setBatteryPower();
    setScreenSize();
    setHasWiFi();
    setHasBluetooth();
}




