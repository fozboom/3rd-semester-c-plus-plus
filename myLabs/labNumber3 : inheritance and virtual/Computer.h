#ifndef UNTITLED_COMPUTER_H
#define UNTITLED_COMPUTER_H
#include "header.h"
#include <iostream>
#include <cstdlib>

const int SIZE = 30;

enum operatingSystem {Windows, MacOS, Linux, Android, IOS, noname};
enum chargingType {USB_C, microUSB, Lightning};

class Computer
{
protected:
    char brandName[SIZE]{};                   //имя бренда
    char modelName[SIZE]{};                   //имя модели
    int RAM;                                //количество оперативной памяти
    double storageCapacity;                 //объем хранилища
    operatingSystem system;                 //тип операционной системы
    double price;                           //цена
    double weight;                          //вес
public:
    Computer();
    Computer(const Computer &other);
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

    void setComputerCase();
    char* getComputerCase();

    void setGraphicCardModel();
    char* getGraphicCardModel();

    void setPortCount();
    int getPortCount() const;

    void setPowerBlock();
    double getPowerBlock() const;
};
};

class Monoblock : public Desktop
{
protected:
    double screenSize;                      //размер экрана
    bool hasTouchscreen;                    //сенсорный ли экран
    int cameraResolution;                   //разрешение камеры
};

class PortableDevice : public Computer
{
protected:
    int batteryPower;                       //мощность батареи
    double screenSize;                      //размер экрана
    bool hasWiFi;                           //наличие wi-fi
    bool hasBluetooth;                      //наличие bluetooth
};

class Laptop : public PortableDevice
{
protected:
    int keyCount;
    int portCount;                          //кол-во портов
    bool keyboardBacklight;                 //подсветка клавиатуры
    double touchpadSize;                    //размер тачпада
};

class tabletComputer : public PortableDevice
{
    bool hasStylus;                         //наличие стилуса
    bool hasSIM;                            //наличие симки
    bool hasGPS;                            //наличие GPS;
    chargingType power;                     //тип зарядки
    double screenSize;                      //размер экрана
};






#endif //UNTITLED_COMPUTER_H
