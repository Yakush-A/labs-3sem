#ifndef EVENTTIME_H
#define EVENTTIME_H

#include <chrono>

class EventTime
{
private:
    std::chrono::hours hours;
    std::chrono::minutes minutes;

public:
    EventTime(int h, int m);
    virtual int getHours() const;
    virtual int getMinutes() const;
    virtual void setTime(int h, int m);

};


#endif