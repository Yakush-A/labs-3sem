#ifndef EXAMGRADE_H
#define EXAMGRADE_H

#include"grade.h"

class ExamGrade : public Grade 
{
protected:
    int retakeCount;

public:
    virtual int getRetakeCount() const;
    virtual void setRetakeCount(int count);
};


#endif