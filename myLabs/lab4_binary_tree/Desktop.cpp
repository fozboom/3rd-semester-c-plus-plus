#include "Computer.h"

void Desktop::setComputerCase()
{
    rewind(stdin);
    std::cout << "\nВведите тип корпуса - ";
    std::cin.getline(computerCase, SIZE, '\n');
}

char* Desktop::getComputerCase()
{
    return this->computerCase;
}

void Desktop::setGraphicCardModel()
{
    rewind(stdin);
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
    std::cout << "\nВведите мощность блока питания - ";
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
    strcpy(this->computerCase, other.computerCase);
    strcpy(this->graphicCardModel, other.graphicCardModel);
    this->portCount = other.portCount;
    this->powerBlock = other.powerBlock;
}

Desktop::~Desktop()
{

}

void Desktop::inputData()
{
    Computer::inputData();
    setComputerCase();
    setGraphicCardModel();
    setPortCount();
    setPowerBlock();
}

void Desktop::print()
{
    std::cout << "\033[31mDESKTOP\033[0m" << std::endl;
    banner();
    std::cout.width(SIZE/2);
    std::cout   << "computerCase" << std::setw(SIZE/2)
                << "grCardModel" << std::setw(SIZE/2)
                << "portCount" << std::setw(SIZE/2)
                << "powerBlock" << std::endl;
    Computer::print();
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << computerCase << std::setw(SIZE/2)
                << graphicCardModel << std::setw(SIZE/2)
                << portCount << std::setw(SIZE/2)
                << powerBlock << std::endl;
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
}





