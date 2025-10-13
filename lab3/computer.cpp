#include"computer.h"
inline void Computer::setRAM(unsigned size)
{
    this->RAMInGBytes = size;
}
inline void Computer::setStorage(unsigned capacity)
{
    this->storageCapacityInGBytes = capacity;
}
inline void Computer::setCPUName(std::string name)
{
    this->CPUName = name;
}
inline void Computer::setGPUName(std::string name)
{
    this->GPUName = name;
}

inline unsigned Computer::getRAM()
{
    return RAMInGBytes;
}
inline unsigned Computer::getStorage()
{
    return storageCapacityInGBytes;
}
inline std::string Computer::getCPUName()
{
    return CPUName;
}
inline std::string Computer::getGPUName()
{
    return GPUName;
} 


inline void Computer::printTable()
{
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор|"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, Computer& PC)
{
    os<<'|'<<
        std::setw(5)<<std::left<<PC.RAMInGBytes<<'|'<<
        std::setw(5)<<std::left<<PC.storageCapacityInGBytes<<'|'<<
        std::setw(15)<<std::left<<PC.CPUName<<'|'<<
        std::setw(15)<<std::left<<PC.GPUName<<'|';
    return os;
} 

