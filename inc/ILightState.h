#pragma once

class ILightState
{
public:
    virtual ~ILightState(){};

    virtual void handleEvent(EEvent) = 0;
};
