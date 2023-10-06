#include "Computer.h"

void Desktop::setComputerCase()
{
    std::cout << "\nВведите тип корпуса - ";
    std::cin.getline(computerCase, SIZE, '\n');
}

char* Desktop::getComputerCase()
{
    return this->computerCase;
}

void Desktop::setGraphicCardModel()
{
    std::cout << "\nВведите модель графической карты - ";
    std::cin.getline(graphicCardModel, SIZE, '\n');
}

char* Desktop::getGraphicCardModel()
{
    return this->graphicCardModel;
}

void Desktop::setPortCount()
{
    std::cout << "\nВведите количество портов - ";
    portCount = inputNumber(0, 100);
}

int Desktop::getPortCount() const
{
    return portCount;
}

void Desktop::setPowerBlock()
{
    std::cout << "Введите мощность блока питания - ";
    powerBlock = inputDouble(0.0, 2000.0);
}

double Desktop::getPowerBlock() const
{
    return powerBlock;
}

Desktop::Desktop(): Computer()
{
    portCount = 0;
    powerBlock = 0.0;
}

Desktop::Desktop(const Desktop &other) : Computer(other)
{
    this->portCount = other.portCount;
    this->powerBlock = other.powerBlock;
}

void Desktop::inputDeskTopData()
{
    inputComputerData();
    setComputerCase();
    setGraphicCardModel();
    setPortCount();
    setPowerBlock();
}


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
