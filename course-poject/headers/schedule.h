#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "academicevent.h"
#include <list>

class Schedule {
private:
    static const int WEEKS_COUNT = 4;
    static const int DAYS_PER_WEEK = 6;
    std::list<AcademicEvent*> schedule[WEEKS_COUNT][DAYS_PER_WEEK];

public:
    void addLesson(int week, int day, AcademicEvent* lesson);
    void removeLesson(int week, int day, AcademicEvent* lesson);
    const std::list<AcademicEvent*>& getLessons(int week, int day) const;
    void clearDay(int week, int day);
    bool hasLessons(int week, int day) const;
};

#endif