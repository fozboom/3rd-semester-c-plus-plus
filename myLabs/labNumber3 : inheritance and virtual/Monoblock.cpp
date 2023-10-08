#include "Computer.h"

Monoblock::Monoblock() :Desktop()
{
    screenSize = 0.0;
    hasTouchscreen = false;
    cameraResolution = 0;
}

Monoblock::Monoblock(const Monoblock& other) : Desktop(other)
{
    this->screenSize = other.screenSize;
    this->hasTouchscreen = other.hasTouchscreen;
    this->cameraResolution = other.cameraResolution;
}

void Monoblock::setScreenSize()
{
    std::cout << "\nВведите размер экрана (дюймы):";
    screenSize = inputDouble(0.0, 100.0);
}

double Monoblock::getScreenSize() const
{
    return screenSize;
}

void Monoblock::setHasTouchscreen()
{
    std::cout << "\nЕсть ли сенсорный экран? (1 - Да, 0 - Нет) - ";
    int choice = inputNumber(0, 1);
    hasTouchscreen = (choice == 1);
}

bool Monoblock::getHasTouchscreen() const
{
    return hasTouchscreen;
}

void Monoblock::setCameraResolution()
{
    std::cout << "\nВведите разрешение камеры (в мегапикселях):";
    cameraResolution = inputNumber(0, 100);
}

int Monoblock::getCameraResolution() const
{
    return cameraResolution;
}

void Monoblock::inputMonoblockData()
{
    inputDeskTopData();
    setScreenSize();
    setHasTouchscreen();
    setCameraResolution();
}

