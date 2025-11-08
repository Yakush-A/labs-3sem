#include"tablet.h"

inline void Tablet::setMultiTouchCapacity(unsigned multiTouch)
{
    multiTouchSensorCapacity = multiTouch;
}

inline unsigned Tablet::getMultiTouchCapacity()
{
    return multiTouchSensorCapacity;
}


inline void Tablet::printTable()
{
    std::cout<<"   | ОЗУ | ПЗУ |   Процессор   |Граф. Процессор| Батарея, Вт*ч |Мультитач |"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, Tablet& PC)
{
        os<<'|'<<
        std::setw(5)<<std::left<<PC.RAMInGBytes<<'|'<<
        std::setw(5)<<std::left<<PC.storageCapacityInGBytes<<'|'<<
        std::setw(15)<<std::left<<PC.CPUName<<'|'<<
        std::setw(15)<<std::left<<PC.GPUName<<'|'<<
        std::setw(15)<<std::left<<PC.batteryCapacityInWH<<'|'<<
        std::setw(10)<<std::left<<PC.multiTouchSensorCapacity<<'|';
    return os;
} 

inline std::istream& operator >> (std::istream& is, Tablet& PC)
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
    std::cout<<"Введите ёмкость мультитач сенсора: ";
    is>>PC.multiTouchSensorCapacity;

    return is;
}
