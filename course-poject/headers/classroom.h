#ifndef CLASSROOM_H
#define CLASSROOM_H

#include<string>

class Classroom 
{
private:
    std::string roomNumber;
    std::string roomType;

public:
    Classroom(const std::string& number, const std::string& type);
    virtual std::string getRoomNumber() const;
    virtual std::string getRoomType() const;
    virtual void setRoomNumber(const std::string& number);
    virtual void setRoomType(const std::string& type);
    virtual std::string toString() const;
};


#endif