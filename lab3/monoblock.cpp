#include"monoblock.h"






inline void Monoblock::printTable()
{
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор|Мощность БП, Вт|Диагональ экрана|"<<std::endl;
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
