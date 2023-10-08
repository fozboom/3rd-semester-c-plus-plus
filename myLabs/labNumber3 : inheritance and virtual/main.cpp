#include "Computer.h"

int main()
{
    Computer * mas[SIZE];
    mas[0] = new Desktop;
    mas[0]->inputData();
    mas[1] = new PortableDevice;
    mas[1]->inputData();
    mas[2] = new Monoblock;
    mas[2]->inputData();
    mas[3] = new Laptop;
    mas[3]->inputData();
    mas[4] = new tabletComputer;
    mas[4]->inputData();
    Computer::prints(mas[0]);
    Computer::prints(mas[1]);
    Computer::prints(mas[2]);
    Computer::prints(mas[3]);
    Computer::prints(mas[4]);
    return 0;
}
