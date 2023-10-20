#ifndef UNTITLED_COMPUTER_H
#define UNTITLED_COMPUTER_H
#include "header.h"
#include <iostream>
//#include <cstdlib>
#include <fstream>
#include <ios>
#include <iomanip>
#include <typeinfo>

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
    char brandName[SIZE]{};                 //имя бренда
    char modelName[SIZE]{};                 //имя модели
    int RAM;                                //количество оперативной памяти
    double storageCapacity;                 //объем хранилища
    operatingSystem system;                 //тип операционной системы
    double price;                           //цена
    double weight;                          //вес

    static int count;                       //кол-во компьютеров
    static Computer * pComputers[];         //массив указателей
public:
    Computer();
    Computer(const Computer &other);
    //Computer(Computer&& other) noexcept ;
    //Computer& operator=(Computer&& other) noexcept;
    virtual ~Computer() = 0;
    virtual void inputData();
    virtual void print();

    static void add();
    static void display();
    static void read();
    static void write();
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


    static void freeMemory()
    {
        for (int i = 0; i < count; i++)
        {
            delete pComputers[i];
        }
    }

    static void banner();
};

class Desktop : public Computer
{
protected:
    char computerCase[SIZE]{};                //тип корпуса
    char graphicCardModel[SIZE]{};            //модель графической карты
    int portCount;                          //кол-во портов
    double powerBlock;                      //мощность блока питания
public:
    Desktop();
    Desktop(const Desktop& other);
    ~Desktop() override;
    //Desktop& operator=(Desktop&& other) noexcept;
    //Desktop(Desktop&& other) noexcept ;
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
};






class Monoblock : public Desktop
{
protected:
    double screenSize;                      //размер экрана
    bool hasTouchscreen;                    //сенсорный ли экран
    int cameraResolution;                   //разрешение камеры
public:
    Monoblock();
    Monoblock(const Monoblock& other);
    ~Monoblock() override;
    //Monoblock(Monoblock&& other) noexcept;
    //Monoblock& operator=(Monoblock&& other) noexcept;
    void inputData() override;
    void print() override;

    void setScreenSize();
    [[nodiscard]] double getScreenSize() const;

    void setHasTouchscreen();
    [[nodiscard]] bool getHasTouchscreen() const;

    void setCameraResolution();
    [[nodiscard]] int getCameraResolution() const;
};






class PortableDevice : public Computer
{
protected:
    int batteryPower;                       //мощность батареи
    double screenSize;                      //размер экрана
    bool hasWiFi;                           //наличие wi-fi
    bool hasBluetooth;                      //наличие bluetooth
public:
    PortableDevice();
    PortableDevice(const PortableDevice& other);
    ~PortableDevice() override;
    //PortableDevice(PortableDevice&& other) noexcept;
    //PortableDevice& operator=(PortableDevice&& other) noexcept;
    void inputData() override;
    void print() override;

    void setBatteryPower();
    [[nodiscard]] int getBatteryPower() const;

    void setScreenSize();
    [[nodiscard]] double getScreenSize() const;

    void setHasWiFi();
    [[nodiscard]] bool getHasWiFi() const;

    void setHasBluetooth();
    [[nodiscard]] bool getHasBluetooth() const;
};






class Laptop : public PortableDevice
{
protected:
    int keyCount;
    int portCount;                          //кол-во портов
    bool keyboardBacklight;                 //подсветка клавиатуры
    double touchpadSize;                    //размер тачпада
public:
    Laptop();
    Laptop(const Laptop &other);
    ~Laptop() override;
    //Laptop(Laptop&& other) noexcept;
    //Laptop& operator= (Laptop&& other) noexcept;
    void inputData () override;
    void print() override;

    void setKeyCount();
    [[nodiscard]] int getKeyCount() const;

    void setPortCount();
    [[nodiscard]] int getPortCount() const;

    void setKeyboardBacklight();
    [[nodiscard]] bool getKeyboardBacklight() const;

    void setTouchpadSize();
    [[nodiscard]] double getTouchpadSize() const;
};






class tabletComputer : public PortableDevice
{
protected:
    bool hasStylus;                         //наличие стилуса
    bool hasSIM;                            //наличие симки
    bool hasGPS;                            //наличие GPS;
    chargingType power;                     //тип зарядки
public:
    tabletComputer();
    tabletComputer(const tabletComputer& other);
    //tabletComputer(tabletComputer&& other) noexcept;
    //tabletComputer& operator= (tabletComputer&& other) noexcept;
    ~tabletComputer() override;
    void inputData() override;
    void print() override;

    void setHasStylus();
    [[nodiscard]] bool getHasStylus() const;

    void setHasSIM();
    [[nodiscard]] bool getHasSIM() const;

    void setHasGPS();
    [[nodiscard]] bool getHasGPS() const;

    void setPower();
    [[nodiscard]] chargingType getPower() const;

};






#endif //UNTITLED_COMPUTER_H
