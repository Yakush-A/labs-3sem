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
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор| Батарея, Вт*ч |Раскладка |"<<std::endl;
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
