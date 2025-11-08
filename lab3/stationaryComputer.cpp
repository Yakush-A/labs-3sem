#include"stationaryComputer.h"

inline void StationaryComputer::setPSUPower(unsigned power)
{
    PSUPowerInWatts = power;
}

inline unsigned StationaryComputer::getPSUPower()
{
    return PSUPowerInWatts;
}


inline void StationaryComputer::printTable()
{
    std::cout<<"   | ОЗУ | ПЗУ |   Процессор   |Граф. Процессор|Мощность БП, Вт|"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, StationaryComputer& PC)
{
    os<<'|'<<
        std::setw(5)<<std::left<<PC.RAMInGBytes<<'|'<<
        std::setw(5)<<std::left<<PC.storageCapacityInGBytes<<'|'<<
        std::setw(15)<<std::left<<PC.CPUName<<'|'<<
        std::setw(15)<<std::left<<PC.GPUName<<'|'<<
        std::setw(15)<<std::left<<PC.PSUPowerInWatts<<'|';
    return os;
} 

inline std::istream& operator >> (std::istream& is, StationaryComputer& PC)
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
    std::cout<<"Введите мощность блока питания (Вт): ";
    is>>PC.PSUPowerInWatts;

    return is;
}