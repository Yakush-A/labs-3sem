#ifndef CAMPUSEVENT_H
#define CAMPUSEVENT_H

#include "classroom.h"
#include "person.h"
#include "academicevent.h"
#include <list>

class CampusEvent : public AcademicEvent 
{
protected:
    std::list<Person*> participants;
    Classroom* classroom;

public:
    virtual const std::list<Person*>& getParticipants() const;
    virtual Classroom* getClassroom() const;
    virtual void setClassroom(Classroom* room);
    virtual void addParticipant(Person* person);
    virtual void removeParticipant(Person* person);
};

#endif