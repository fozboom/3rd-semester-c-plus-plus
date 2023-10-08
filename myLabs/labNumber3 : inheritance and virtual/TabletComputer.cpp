#include "header.h"
#include "Computer.h"

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



void tabletComputer::inputTabletComputerData()
{
    inputPortableDeviceData();
    setHasStylus();
    setHasSIM();
    setHasGPS();
    setPower();
}

void tabletComputer::print()
{
    std::cout << "\033[31mLAPTOP\033[0m" << std::endl;
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
                << "hasBluetooth" << std::setw(SIZE/2)
                << "hasStylus" << std::setw(SIZE/2)
                << "hasSIM" << std::setw(SIZE/2)
                << "hasGPS" << std::setw(SIZE/2)
                << "chargeType" << std::endl;
    Computer::print();
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << batteryPower << std::setw(SIZE/2)
                << screenSize << std::setw(SIZE/2)
                << hasWiFi << std::setw(SIZE/2)
                << hasBluetooth << std::setw(SIZE/2)
                << hasStylus << std::setw(SIZE/2)
                << hasSIM << std::setw(SIZE/2)
                << hasGPS << std::setw(SIZE/2);
    printChargingType(power);
    std:: cout << std::endl;
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
}
