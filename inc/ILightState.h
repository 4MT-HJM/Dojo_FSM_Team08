#pragma once
#include <memory>

enum class EEvent;
class ILightSwitchFsm;

class ILightState
{
public:
    virtual ~ILightState(){};

    virtual void handleEvent(ILightSwitchFsm*, EEvent) = 0;
};
