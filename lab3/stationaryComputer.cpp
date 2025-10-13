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
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор|Мощность БП, Вт|"<<std::endl;
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
