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


