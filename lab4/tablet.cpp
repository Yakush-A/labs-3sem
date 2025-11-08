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
    std::cout<<"| ОЗУ | ПЗУ |   Процессор   |Граф. Процессор| Батарея, Вт*ч |Мультитач |"<<std::endl;
}

inline std::ostream& operator << (std::ostream& os, Tablet& PC)
{
        os<<static_cast<PortableComputer&>(PC)<<
        std::setw(10)<<std::left<<PC.multiTouchSensorCapacity<<'|';
    return os;
} 

inline std::istream& operator >> (std::istream& is, Tablet& PC)
{
    is>>static_cast<PortableComputer&>(PC);
    std::cout<<"Введите ёмкость мультитач сенсора: ";
    is>>PC.multiTouchSensorCapacity;

    return is;
}

bool Tablet::operator==(const Tablet& other) const 
{
    return PortableComputer::operator==(other) &&
           multiTouchSensorCapacity == other.multiTouchSensorCapacity;
}

bool Tablet::operator!=(const Tablet& other) const 
{
    return !(*this == other);
}

bool Tablet::operator<(const Tablet& other) const 
{
    if (!PortableComputer::operator==(other))
        return PortableComputer::operator<(other);
    return multiTouchSensorCapacity < other.multiTouchSensorCapacity;
}

bool Tablet::operator>(const Tablet& other) const 
{
    return other < *this;
}

bool Tablet::operator<=(const Tablet& other) const 
{
    return !(other < *this);
}

bool Tablet::operator>=(const Tablet& other) const 
{
    return !(*this < other);
}
