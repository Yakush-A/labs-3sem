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


inline std::istream& operator >> (std::istream& is, Computer& PC)
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
 
    return is;
}

bool Computer::operator==(const Computer& other) const
{
    return RAMInGBytes == other.RAMInGBytes &&
           storageCapacityInGBytes == other.storageCapacityInGBytes &&
           CPUName == other.CPUName &&
           GPUName == other.GPUName;
}

bool Computer::operator!=(const Computer& other) const {
    return !(*this == other);
}

bool Computer::operator<(const Computer& other) const {
    if (RAMInGBytes != other.RAMInGBytes)
        return RAMInGBytes < other.RAMInGBytes;
    if (storageCapacityInGBytes != other.storageCapacityInGBytes)
        return storageCapacityInGBytes < other.storageCapacityInGBytes;
    if (CPUName != other.CPUName)
        return CPUName < other.CPUName;
    return GPUName < other.GPUName;
}

bool Computer::operator>(const Computer& other) const {
    return other < *this;
}

bool Computer::operator<=(const Computer& other) const {
    return !(other < *this);
}

bool Computer::operator>=(const Computer& other) const {
    return !(*this < other);
}