#ifndef GROUP_H
#define GROUP_H

#include "student.h"
#include <list>

class Group 
{
private:
    std::list<Student*> students;
    std::string groupNumber;     
    int facultyId;               
    std::string specialty;       

public:
    // Геттеры
    const std::string& getGroupNumber() const;
    int getFacultyId() const;
    const std::string& getSpecialty() const;
    const std::list<Student*>& getStudents() const;
    
    // Сеттеры
    void setGroupNumber(const std::string& number);
    void setFacultyId(int faculty);
    void setSpecialty(const std::string& spec);
};

#endif