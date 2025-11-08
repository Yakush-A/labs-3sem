#ifndef PERSON_H
#define PERSON_H

#include<string>

class Person 
{
protected:
    std::string firstName;
    std::string lastName;
    std::string middleName;

public:
    // Геттеры
    virtual std::string getFirstName() const;
    virtual std::string getLastName() const;
    virtual std::string getMiddleName() const;

    // Сеттеры
    virtual void setFirstName(const std::string& first);
    virtual void setLastName(const std::string& last);
    virtual void setMiddleName(const std::string& middle);
};

#endif