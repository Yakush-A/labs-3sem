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
    os<<
        static_cast<Computer&>(PC)<<
        std::setw(15)<<std::left<<PC.PSUPowerInWatts<<'|';
    return os;
} 

inline std::istream& operator >> (std::istream& is, StationaryComputer& PC)
{
    is>>static_cast<Computer&>(PC);
    std::cout<<"Введите мощность блока питания (Вт): ";
    is>>PC.PSUPowerInWatts;

    return is;
}

bool StationaryComputer::operator==(const StationaryComputer& other) const 
{
    return Computer::operator==(other) &&
           PSUPowerInWatts == other.PSUPowerInWatts;
}

bool StationaryComputer::operator!=(const StationaryComputer& other) const 
{
    return !(*this == other);
}

bool StationaryComputer::operator<(const StationaryComputer& other) const 
{
    if (!Computer::operator==(other))
        return Computer::operator<(other);
    return PSUPowerInWatts < other.PSUPowerInWatts;
}

bool StationaryComputer::operator>(const StationaryComputer& other) const 
{
    return other < *this;
}

bool StationaryComputer::operator<=(const StationaryComputer& other) const 
{
    return !(other < *this);
}

bool StationaryComputer::operator>=(const StationaryComputer& other) const 
{
    return !(*this < other);
}