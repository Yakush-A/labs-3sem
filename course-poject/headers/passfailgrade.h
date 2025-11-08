#ifndef PASSFAILGRADE_H
#define PASSFAILGRADE_H

#include "examgrade.h"

class PassFailGrade : public ExamGrade
{
protected:
    bool passed;

public:
    virtual bool isPassed() const;
    virtual void setPassed(bool status);
};



#endif