#ifndef UNTITLED_COMPUTER_H
#define UNTITLED_COMPUTER_H
#include <iostream>
#include "header.h"
#include <fstream>
#include <ios>
#include <iomanip>
#include <typeinfo>

#include "Exception.h"

const int SIZE = 30;
const int MAX_SIZE = 50;

enum operatingSystem {Windows, MacOS, Linux, Android, IOS, noname};
enum chargingType {USB_C, microUSB, Lightning, noPower};
enum computerType {tDesktop, tMonoblock, tLaptop, tPortableDevice, tTabletComputer};

operatingSystem choiceSystem ();
void printOperatingSystem (operatingSystem type);
chargingType choicePower();
void printChargingType(chargingType type);


class Computer
{
protected:
    char brandName[SIZE];                 //имя бренда
    char modelName[SIZE];                 //имя модели
    int RAM;                                //количество оперативной памяти
    double storageCapacity;                 //объем хранилища
    operatingSystem system;                 //тип операционной системы
    double price;                           //цена
    double weight;                          //вес
    int count = 0;
public:
    Computer();
    Computer(const Computer &other);

    virtual ~Computer() = 0;
    virtual void inputData();
    virtual void print();

    computerType getType();

    void setBrandName ();
    char* getBrandName ();

    void setModelName ();
    char* getModelName ();

    void setRAM ();
    [[nodiscard]] int getRAM () const;

    void setStorageCapacity();
    [[nodiscard]] double getStorageCapacity() const;

    void setSystem();
    operatingSystem getSystem();

    void setPrice();
    [[nodiscard]] double getPrice() const;

    void setWeight();
    [[nodiscard]] double getWeight() const;

    int getCount () const { return count;}
    void setCount(int v) {count = v;}

    static void banner();

};

class Desktop : public Computer
{
protected:
    char computerCase[SIZE];                //тип корпуса
    char graphicCardModel[SIZE];            //модель графической карты
    int portCount;                          //кол-во портов
    double powerBlock;                      //мощность блока питания
public:
    Desktop();
    Desktop(const Desktop& other);
    ~Desktop() override;

    void inputData () override;
    void print() override;

    void setComputerCase();
    char* getComputerCase();

    void setGraphicCardModel();
    char* getGraphicCardModel();

    void setPortCount();
    [[nodiscard]] int getPortCount() const;

    void setPowerBlock();
    [[nodiscard]] double getPowerBlock() const;

    bool operator == (const Desktop&) const;
    bool operator != (const Desktop&) const;
    bool operator >= (const Desktop&) const;
    bool operator <= (const Desktop&) const;
    bool operator > (const Desktop&) const;
    bool operator < (const Desktop&) const;

    friend std::ostream& operator<<(std::ostream& os, Desktop& desktop);
    friend std::ofstream& operator<<(std::ofstream& os, Desktop& desktop);
    friend std::ifstream& operator>>(std::ifstream& is, Desktop& desktop);
};










#endif //UNTITLED_COMPUTER_H
