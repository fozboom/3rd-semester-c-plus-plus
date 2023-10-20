#include "Computer.h"

Computer::~Computer()
{
    std::cout << "\nДеструктор класса Computer";
}

void Computer::setBrandName()
{
    std::cout << "\nВведите название бренда - ";
    std::cin.getline(brandName, SIZE, '\n');
}

char* Computer::getBrandName()
{
    return this->brandName;
}

void Computer::setModelName()
{
    std::cout << "\nВведите название модели - ";
    std::cin.getline(modelName, SIZE, '\n');
}

char *Computer::getModelName()
{
    return this->modelName;
}

void Computer::setRAM()
{
    std::cout << "\nВведите кол-во оперативной памяти:";
    RAM = inputNumber(0, 64);
}

int Computer::getRAM() const
{
    return RAM;
}

void Computer::setStorageCapacity()
{
    std::cout << "\nВведите объем SSD:";
    storageCapacity = inputDouble(0.0, 2056.0);
}

double Computer::getStorageCapacity() const
{
    return storageCapacity;
}

void Computer::setSystem()
{
    system = choiceSystem();

}

operatingSystem Computer::getSystem()
{
    return system;
}

void Computer::setPrice()
{
    std::cout << "Введите цену:";
    price = inputDouble(0.0, 100000.0);
}

double Computer::getPrice() const
{
    return price;
}

void Computer::setWeight()
{
    std::cout << "Введите вес:";
    weight = inputDouble(0.0, 100000.0);
}

double Computer::getWeight() const
{
    return weight;
}

Computer::Computer()
{
    std::cout << "\nКонструктор класса Computer";
    RAM = 0;
    storageCapacity = 0.0;
    system = noname;
    price = 0.0;
    weight = 0.0;
}

Computer::Computer(const Computer &other)
{
    strcpy(this->brandName, other.brandName);
    strcpy(this->modelName, other.modelName);
    this->RAM = other.RAM;
    this->storageCapacity = other.storageCapacity;
    this->system = other.system;
    this->price = other.price;
    this->weight = other.weight;
}

void Computer::inputData()
{
    setBrandName();
    setModelName();
    setRAM();
    setStorageCapacity();
    setSystem();
    setPrice();
    setWeight();
}

void Computer::print()
{

    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << brandName << std::setw(SIZE/2)
                << modelName << std::setw(SIZE/2)
                << RAM << std::setw(SIZE/2)
                << storageCapacity;
    printOperatingSystem(system);
    std::cout.width(SIZE/2);
    std::cout   << price << std::setw(SIZE/2)
                << weight;
}

void Computer::banner()
{
    std::cout << "\033[32m" << std::setfill('-') << std::setw(8*SIZE) << "" << std::setfill(' ') << "\033[0m" <<  std::endl;
    std::cout.setf(std::ios::left);
    std::cout.width(SIZE/2);
    std::cout   << "brandName" << std::setw(SIZE/2)
                << "modelName" << std::setw(SIZE/2)
                << "RAM" << std::setw(SIZE/2)
                << "stCapacity" <<  std::setw(SIZE/2)
                << "opSystem" <<  std::setw(SIZE/2)
                << "price" << std::setw(SIZE/2)
                << "weight";
}

void Computer::add()
{
    char choice;
    std::cout << "\n'd' для добавления Desktop"
                 "\n'p' для добавления PortableDevice"
                 "\n'm' для добавления Monoblock"
                 "\n't' для добавления TabletComputer"
                 "\n'l' для добавления Laptop"
            "\nВаш выбор: ";
    std::cin >> choice;
    rewind(stdin);
    switch (choice)
    {
        case 'd': pComputers[count] = new Desktop; break;
        case 'p': pComputers[count] = new PortableDevice; break;
        case 'm': pComputers[count] = new Monoblock; break;
        case 't': pComputers[count] = new tabletComputer; break;
        case 'l': pComputers[count] = new Laptop; break;
        default: std::cout << "Неизвестная команда"; return;
    }

    pComputers[count++]->inputData();
}

void Computer::display()
{
    for(int i = 0; i < count; ++i)
        pComputers[i]->print();
}

void Computer::read()
{
    count = 0;
    computerType type;
    std::ifstream file;
    file.open("COMPUTER", std::ios::binary);
    if (!file) {std::cout << "Ошибка открытия файла для записи"; exit(EXIT_FAILURE);}

    while(true)
    {
        file.read(reinterpret_cast<char*>(&type), sizeof(type));
        if(file.eof())
            break;
        switch (type)
        {
            case tDesktop:{
                Desktop tmpDesktop;
                file.read((char*)(&tmpDesktop), sizeof(Desktop));
                pComputers[count] = new Desktop(tmpDesktop);
                break;}
            case tPortableDevice:{
                PortableDevice tmpPortable;
                file.read((char*)(&tmpPortable), sizeof(PortableDevice));
                pComputers[count] = new PortableDevice(tmpPortable);
                break;}
            case tMonoblock:{
                Monoblock tmpMonoblock;
                file.read((char*)(&tmpMonoblock), sizeof(Monoblock));
                pComputers[count] = new Monoblock(tmpMonoblock);
                break;}
            case tLaptop:{
                Laptop tmpLaptop;
                file.read((char*)(&tmpLaptop), sizeof(Laptop));
                pComputers[count] = new Laptop(tmpLaptop);
                break;}
            case tTabletComputer:{
                tabletComputer tmpTablet;
                file.read((char*)(&tmpTablet), sizeof(tabletComputer));
                pComputers[count] = new tabletComputer(tmpTablet);
                break;}
            default:
                std::cout << "Ошибка"; exit(EXIT_FAILURE);
        }
        if(!file){ std::cout << "\nЧтение данных из файла невозможно\n"; return;}

        count++;
    }
}

void Computer::write()
{
    int size;
    computerType type;
    std::ofstream file;
    file.open("COMPUTER", std::ios::binary);

    if (!file) {std::cout << "Ошибка открытия файла для записи"; exit(EXIT_FAILURE);}

    for (int i = 0; i < count; ++i)
    {
        type = pComputers[i]->getType();
        file.write(reinterpret_cast<char*>(&type), sizeof(type));
        switch (type)
        {
            case tDesktop: size = sizeof(Desktop); break;
            case tPortableDevice: size = sizeof(PortableDevice); break;
            case tMonoblock: size = sizeof(Monoblock); break;
            case tLaptop: size = sizeof(Laptop); break;
            case tTabletComputer: size = sizeof(tabletComputer); break;
            default: std::cout << "Ошибка"; exit(EXIT_FAILURE);
        }
        file.write((char*)(pComputers[i]), size);
    }
}

computerType Computer::getType()
{
    if (typeid(*this) == typeid(Desktop))
        return tDesktop;
    if (typeid(*this) == typeid(Monoblock))
        return tMonoblock;
    if (typeid(*this) == typeid(PortableDevice))
        return tPortableDevice;
    if (typeid(*this) == typeid(tabletComputer))
        return tTabletComputer;
    if (typeid(*this) == typeid(Laptop))
        return tLaptop;
    else
        std::cout << "Неправильный тип работника"; exit(EXIT_FAILURE);
}

//Computer::Computer(Computer&& other) noexcept
//{
//    strcpy(this->brandName, other.brandName);
//    strcpy(this->modelName, other.modelName);
//    this->RAM = other.RAM;
//    this->storageCapacity = other.storageCapacity;
//    this->system = other.system;
//    this->price = other.price;
//    this->weight = other.weight;
//
//    strcpy(other.brandName, "");
//    strcpy(other.modelName, "");
//    other.RAM = 0;
//    other.storageCapacity = 0.0;
//    other.system = noname;
//    other.price = 0.0;
//    other.weight = 0.0;
//}
//
//Computer& Computer::operator=(Computer &&other) noexcept
//{
//    if(this != &other)
//    {
//        strcpy(this->brandName, other.brandName);
//        strcpy(this->modelName, other.modelName);
//        this->RAM = other.RAM;
//        this->storageCapacity = other.storageCapacity;
//        this->system = other.system;
//        this->price = other.price;
//        this->weight = other.weight;
//
//        strcpy(other.brandName, "");
//        strcpy(other.modelName, "");
//        other.RAM = 0;
//        other.storageCapacity = 0.0;
//        other.system = noname;
//        other.price = 0.0;
//        other.weight = 0.0;
//    }
//    return *this;
//}
