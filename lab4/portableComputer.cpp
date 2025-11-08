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
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор| Батарея, Вт*ч |"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, PortableComputer& PC)
{
    os<<
        static_cast<Computer&>(PC)<<
        std::setw(15)<<std::left<<PC.batteryCapacityInWH<<'|';
    return os;
}


inline std::istream& operator >> (std::istream& is, PortableComputer& PC)
{
    is>>static_cast<Computer&>(PC);
    std::cout<<"Введите ёмкость аккумулятора (Вт*ч): ";
    is>>PC.batteryCapacityInWH;

    return is;
}

bool PortableComputer::operator==(const PortableComputer& other) const 
{
    return Computer::operator==(other) &&
           batteryCapacityInWH == other.batteryCapacityInWH;
}

bool PortableComputer::operator!=(const PortableComputer& other) const 
{
    return !(*this == other);
}

bool PortableComputer::operator<(const PortableComputer& other) const 
{
    if (!Computer::operator==(other))
        return Computer::operator<(other);
    return batteryCapacityInWH < other.batteryCapacityInWH;
}

bool PortableComputer::operator>(const PortableComputer& other) const 
{
    return other < *this;
}

bool PortableComputer::operator<=(const PortableComputer& other) const 
{
    return !(other < *this);
}

bool PortableComputer::operator>=(const PortableComputer& other) const 
{
    return !(*this < other);
}