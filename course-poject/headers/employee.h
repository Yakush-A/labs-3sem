#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person {
protected:
    std::string position;
    
public:
    // Геттеры
    virtual std::string getPosition() const;

    // Сеттеры
    virtual void setPosition(const std::string& pos);
};

#endif