#pragma once

class Screen
{
private:
    double screenSizeInInches;
public:
    virtual void setSreenSize(double) = 0;
};