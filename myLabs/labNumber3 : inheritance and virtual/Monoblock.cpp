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
    Desktop::inputData();
    setScreenSize();
    setHasTouchscreen();
    setCameraResolution();
}

void Monoblock::print()
{
    std::cout << "\033[31mMONOBLOCK\033[0m" << std::endl;
    banner();
    std::cout.width(SIZE/2);
    std::cout   << "computerCase" << std::setw(SIZE/2)
                << "grCardModel" << std::setw(SIZE/2)
                << "portCount" << std::setw(SIZE/2)
                << "powerBlock" << std::setw(SIZE/2)
                << "scrSize" << std::setw(SIZE/2)
                << "TouchScreen" << std::setw(SIZE/2)
                << "camRes" <<std::endl;
    Computer::print();
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << computerCase << std::setw(SIZE/2)
                << graphicCardModel << std::setw(SIZE/2)
                << portCount << std::setw(SIZE/2)
                << powerBlock << std::setw(SIZE/2)
                << screenSize << std::setw(SIZE/2)
                << hasTouchscreen << std::setw(SIZE/2)
                << cameraResolution <<std::endl;
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
}

