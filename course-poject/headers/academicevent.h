#ifndef ACADEMICEVENT_N
#define ACADEMICEVENT_N

#include <string>
#include "eventtime.h"

class AcademicEvent
{
protected:
    std::string name;
    std::string description;
    EventTime* startTime;
    EventTime* endTime;

public:
    virtual std::string getName() const;
    virtual std::string getDescription() const;
    virtual EventTime* getStartTime() const;
    virtual EventTime* getEndTime() const;
    virtual void setName(const std::string& eventName);
    virtual void setDescription(const std::string& desc);
    virtual void setStartTime(EventTime* start);
    virtual void setEndTime(EventTime* end);
    
};




#endif