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

Laptop::Laptop()
{
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

void Laptop::inputLaptopData()
{
    inputPortableDeviceData();
    setKeyCount();
    setPortCount();
    setKeyboardBacklight();
    setTouchpadSize();
}

tabletComputer::tabletComputer()
{
    hasStylus = false;
    hasSIM = false;
    hasGPS = false;
    power = USB_C;
    screenSize = 0.0;
}

// Конструктор копирования
tabletComputer::tabletComputer(const tabletComputer& other) : PortableDevice(other)
{
    hasStylus = other.hasStylus;
    hasSIM = other.hasSIM;
    hasGPS = other.hasGPS;
    power = other.power;
    screenSize = other.screenSize;
}

void tabletComputer::setHasStylus()
{
    std::cout << "\nЕсть ли стилус? (1 - Да, 0 - Нет) - ";
    int choice = inputNumber(0, 1);
    hasStylus = (choice == 1);
}

bool tabletComputer::getHasStylus() const
{
    return hasStylus;
}

void tabletComputer::setHasSIM()
{
    std::cout << "\nЕсть ли сим-карта? (1 - Да, 0 - Нет) - ";
    int choice = inputNumber(0, 1);
    hasSIM = (choice == 1);
}

bool tabletComputer::getHasSIM() const
{
    return hasSIM;
}

void tabletComputer::setHasGPS()
{
    std::cout << "\nЕсть ли GPS? (1 - Да, 0 - Нет) - ";
    int choice = inputNumber(0, 1);
    hasGPS = (choice == 1);
}

bool tabletComputer::getHasGPS() const
{
    return hasGPS;
}

void tabletComputer::setPower()
{
    power = choicePower();
}

chargingType tabletComputer::getPower() const
{
    return power;
}

void tabletComputer::setSizeScreen()
{
    std::cout << "\nВведите размер экрана (дюймы) - ";
    screenSize = inputDouble(0.0, 30.0);
}

double tabletComputer::getSizeScreen() const
{
    return screenSize;
}

void tabletComputer::inputTabletComputerData()
{
    inputPortableDeviceData();
    setHasStylus();
    setHasSIM();
    setHasGPS();
    setPower();
    setSizeScreen();
}
