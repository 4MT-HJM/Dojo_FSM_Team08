#pragma once

enum class EEvent;

class ILightState
{
public:
    virtual ~ILightState(){};

    virtual void handleEvent(EEvent) = 0;
};
