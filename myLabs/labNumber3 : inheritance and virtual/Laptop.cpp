#include "Computer.h"

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
