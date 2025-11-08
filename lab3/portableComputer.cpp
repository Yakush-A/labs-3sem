#include"portableComputer.h"


inline void PortableComputer::setBatteryCapacity(unsigned capacity)
{
    batteryCapacityInWH = capacity;
}
inline unsigned PortableComputer::getBatteryCapacity()
{
    return batteryCapacityInWH;
}


inline void PortableComputer::printTable()
{
    std::cout<<"   | ОЗУ | ПЗУ |   Процессор   |Граф. Процессор| Батарея, Вт*ч |"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, PortableComputer& PC)
{
    os<<'|'<<
        std::setw(5)<<std::left<<PC.RAMInGBytes<<'|'<<
        std::setw(5)<<std::left<<PC.storageCapacityInGBytes<<'|'<<
        std::setw(15)<<std::left<<PC.CPUName<<'|'<<
        std::setw(15)<<std::left<<PC.GPUName<<'|'<<
        std::setw(15)<<std::left<<PC.batteryCapacityInWH<<'|';
    return os;
}


inline std::istream& operator >> (std::istream& is, PortableComputer& PC)
{
    std::cout<<"Введите объём ОЗУ (ГБ): ";
    is>>PC.RAMInGBytes;
    std::cout<<"Введите объём ПЗУ (ГБ): ";
    is>>PC.storageCapacityInGBytes;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Введите имя процессора: ";
    std::getline(is, PC.CPUName, '\n');
    std::cout<<"Введите имя графического процессора: ";
    std::getline(is, PC.GPUName, '\n');
    std::cout<<"Введите ёмкость аккумулятора (Вт*ч): ";
    is>>PC.batteryCapacityInWH;

    return is;
}