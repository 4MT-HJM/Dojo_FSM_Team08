#pragma once
#include <memory>

enum class EEvent;

class ILightState
{
public:
    virtual ~ILightState(){};

    virtual void handleEvent(EEvent, std::shared_ptr<ILightState>&) = 0;
};
