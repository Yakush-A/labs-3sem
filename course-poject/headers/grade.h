#ifndef GRADE_H
#define GRADE_H

#include "eventtime.h"
#include <string>

// Уровень 1: Базовый класс для оценок
class Grade 
{
protected:
    int studentId;
    int grade;
    
    EventTime* classTime;
    std::string subject;

public:
    virtual int getStudentId() const;
    virtual int getGrade() const;
    virtual EventTime* getEventTime() const;
    virtual std::string getSubject() const;
    virtual void setStudentId(int id);
    virtual void setGrade(int gr);
    virtual void setEventTime(EventTime* time);
    virtual void setSubject(const std::string& subj);
};

#endif