#include "header.h"
#include "Computer.h"

TabletComputer::TabletComputer()
{
    std::cout << "\nКонструктор класса TabletComputer";
    hasStylus = false;
    hasSIM = false;
    hasGPS = false;
    power = noPower;
    screenSize = 0.0;
}

// Конструктор копирования
TabletComputer::TabletComputer(const TabletComputer& other) : PortableDevice(other)
{
    this->hasStylus = other.hasStylus;
    this->hasSIM = other.hasSIM;
    this->hasGPS = other.hasGPS;
    this->power = other.power;
    this->screenSize = other.screenSize;
}

void TabletComputer::setHasStylus()
{
    std::cout << "\nЕсть ли стилус? (1 - Да, 0 - Нет) - ";
    int choice = inputNumber(0, 1);
    hasStylus = (choice == 1);
}

bool TabletComputer::getHasStylus() const
{
    return hasStylus;
}

void TabletComputer::setHasSIM()
{
    std::cout << "\nЕсть ли сим-карта? (1 - Да, 0 - Нет) - ";
    int choice = inputNumber(0, 1);
    hasSIM = (choice == 1);
}

bool TabletComputer::getHasSIM() const
{
    return hasSIM;
}

void TabletComputer::setHasGPS()
{
    std::cout << "\nЕсть ли GPS? (1 - Да, 0 - Нет) - ";
    int choice = inputNumber(0, 1);
    hasGPS = (choice == 1);
}

bool TabletComputer::getHasGPS() const
{
    return hasGPS;
}

void TabletComputer::setPower()
{
    power = choicePower();
}

chargingType TabletComputer::getPower() const
{
    return power;
}



void TabletComputer::inputData()
{
    PortableDevice::inputData();
    setHasStylus();
    setHasSIM();
    setHasGPS();
    setPower();
}

void TabletComputer::print()
{
    std::cout << "\033[31mLAPTOP\033[0m" << std::endl;
    banner();
    std::cout.width(SIZE/2);
    std::cout   << "batteryPower" << std::setw(SIZE/2)
                << "screenSize" << std::setw(SIZE/2)
                << "hasWifi" << std::setw(SIZE/2)
                << "hasBluetooth" << std::setw(SIZE/2)
                << "hasStylus" << std::setw(SIZE/2)
                << "hasSIM" << std::setw(SIZE/2)
                << "hasGPS" << std::setw(SIZE/2)
                << "chargeType" << std::endl;
    Computer::print(); // NOLINT(bugprone-parent-virtual-call)
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

TabletComputer::~TabletComputer()
{
    std::cout << "\nДеструктор класса TabletComputer";
}

//TabletComputer::TabletComputer(TabletComputer &&other) noexcept: PortableDevice(std::move(other))
//{
//    this->hasStylus = other.hasStylus;
//    this->hasSIM = other.hasSIM;
//    this->hasGPS = other.hasGPS;
//    this->power = other.power;
//    this->screenSize = other.screenSize;
//
//    other.hasStylus = false;
//    other.hasSIM = false;
//    other.hasGPS = false;
//    other.power = noPower;
//    other.screenSize = 0.0;
//}
//
//TabletComputer &TabletComputer::operator=(TabletComputer &&other) noexcept
//{
//    if (this != &other)
//    {
//
//    }
//    return *this;
//}
