#ifndef LESSON_H
#define LESSON_H

#include "academicevent.h"
#include "eventtime.h"
#include "classroom.h"
#include "group.h"
#include "teacher.h"

#include <list>

class Lesson : public AcademicEvent 
{
protected:
    std::list<Group*> groups;
    std::list<Teacher*> teachers;

    Classroom* classroom;
    std::string subject;

public:
    virtual const std::list<Group*>& getGroups() const;
    virtual const std::list<Teacher*>& getTeachers() const;
    virtual EventTime* getStartTime() const;
    virtual EventTime* getEndTime() const;
    virtual Classroom* getClassroom() const;
    virtual std::string getSubject() const;
    virtual void setStartTime(EventTime* start);
    virtual void setEndTime(EventTime* end);
    virtual void setClassroom(Classroom* room);
    virtual void setSubject(const std::string& subj);
};

#endif