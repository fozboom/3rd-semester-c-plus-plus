#include "header.h"
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
