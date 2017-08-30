#pragma once

class IBulb
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~IBulb() = default;
};
