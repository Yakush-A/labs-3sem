#include"monoblock.h"

inline void Monoblock::setScreenSize(float diagonal)
{
    screenSize = diagonal;
}

inline float Monoblock::getScreenSize()
{
    return screenSize;
}


inline void Monoblock::printTable()
{
    std::cout<<"   | ОЗУ | ПЗУ |   Процессор   |Граф. Процессор|Мощность БП, Вт|Диагональ экрана|"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, Monoblock& PC)
{
    os<<'|'<<
        std::setw(5)<<std::left<<PC.RAMInGBytes<<'|'<<
        std::setw(5)<<std::left<<PC.storageCapacityInGBytes<<'|'<<
        std::setw(15)<<std::left<<PC.CPUName<<'|'<<
        std::setw(15)<<std::left<<PC.GPUName<<'|'<<
        std::setw(15)<<std::left<<PC.PSUPowerInWatts<<'|'<<
        std::setw(16)<<std::left<<PC.screenSize<<'|';
    return os;
}

inline std::istream& operator >> (std::istream& is, Monoblock& PC)
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
    std::cout<<"Введите мощность блока питания (Вт): ";
    is>>PC.PSUPowerInWatts;    
    std::cout<<"Введите диагональ экрана: ";
    is>>PC.screenSize;

    return is;
}