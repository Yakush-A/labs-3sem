#ifndef STUDENT_H
#define STUDENT_H

const unsigned GROUP_NUMBER_LENGTH = 6;

#include"person.h"

class Student : public Person 
{
protected:
    char groupNumber[GROUP_NUMBER_LENGTH+1];
    int studentId;

public:
    // Геттеры
    virtual const char* getGroupNumber() const;

    // Сеттеры
    virtual void setGroupNumber(const std::string& group);
};

#endif