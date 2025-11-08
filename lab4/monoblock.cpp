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
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор|Мощность БП, Вт|Диагональ экрана|"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, Monoblock& PC)
{
    os<<
        static_cast<StationaryComputer&>(PC)<<
        std::setw(16)<<std::left<<PC.screenSize<<'|';
    return os;
}

inline std::istream& operator >> (std::istream& is, Monoblock& PC)
{
    is>>static_cast<StationaryComputer&>(PC);    
    std::cout<<"Введите диагональ экрана: ";
    is>>PC.screenSize;

    return is;
}



bool Monoblock::operator==(const Monoblock& other) const 
{
    return StationaryComputer::operator==(other) &&
           screenSize == other.screenSize;
}

bool Monoblock::operator!=(const Monoblock& other) const 
{
    return !(*this == other);
}

bool Monoblock::operator<(const Monoblock& other) const 
{
    if (!StationaryComputer::operator==(other))
        return StationaryComputer::operator<(other);
    return screenSize < other.screenSize;
}

bool Monoblock::operator>(const Monoblock& other) const 
{
    return other < *this;
}

bool Monoblock::operator<=(const Monoblock& other) const 
{
    return !(other < *this);
}

bool Monoblock::operator>=(const Monoblock& other) const 
{
    return !(*this < other);
}