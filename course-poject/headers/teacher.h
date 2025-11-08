#ifndef TEACHER_H
#define TEACHER_H

#include"employee.h"

class Teacher : public Employee 
{
protected:
    int teacherId;

public:
    // Геттеры
    virtual int getTeacherId() const;

    // Сеттеры
    virtual void setTeacherId(int id);
};

#endif