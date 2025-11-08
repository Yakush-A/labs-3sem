#include"laptop.h"

inline void Laptop::setKeyboardLayout(std::string layout)
{
    keyboardLayout = layout;
}

inline std::string Laptop::getKeyboardLayout()
{
    return keyboardLayout;
}


inline void Laptop::printTable()
{
    std::cout<<"   | ОЗУ | ПЗУ |   Процессор   |Граф. Процессор| Батарея, Вт*ч |Раскладка |"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, Laptop& PC)
{
        os<<'|'<<
        std::setw(5)<<std::left<<PC.RAMInGBytes<<'|'<<
        std::setw(5)<<std::left<<PC.storageCapacityInGBytes<<'|'<<
        std::setw(15)<<std::left<<PC.CPUName<<'|'<<
        std::setw(15)<<std::left<<PC.GPUName<<'|'<<
        std::setw(15)<<std::left<<PC.batteryCapacityInWH<<'|'<<
        std::setw(10)<<std::left<<PC.keyboardLayout<<'|';

    return os;
}


inline std::istream& operator >> (std::istream& is, Laptop& PC)
{
    std::cout<<"Введите объём ОЗУ (ГБ): ";
    is>>PC.RAMInGBytes;
    std::cout<<"Введите объём ПЗУ (ГБ): ";
    is>>PC.storageCapacityInGBytes;
    std::cout<<"Введите имя процессора: ";
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(is, PC.CPUName, '\n');
    std::cout<<"Введите имя графического процессора: ";
    std::getline(is, PC.GPUName, '\n');
    std::cout<<"Введите ёмкость аккумулятора (Вт*ч): ";
    is>>PC.batteryCapacityInWH;
    std::cout<<"Введите раскладку клавиатуры: ";
    std::getline(is, PC.keyboardLayout, '\n');
 
    return is;
}