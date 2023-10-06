#include "Computer.h"
#include "Desktop.h"

// Конструктор по умолчанию
Desktop::Desktop()
{
    computerCase[0] = '\0';
    graphicCardModel[0] = '\0';
    portCount = 0;
    powerBlock = 0.0;
}

// Конструктор копирования
Desktop::Desktop(const Desktop& other)
{
    strcpy_s(computerCase, SIZE, other.computerCase);
    strcpy_s(graphicCardModel, SIZE, other.graphicCardModel);
    portCount = other.portCount;
    powerBlock = other.powerBlock;
}

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
