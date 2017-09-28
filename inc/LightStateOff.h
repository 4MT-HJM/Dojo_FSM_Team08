#pragma once

#include "ILightState.h"
// #include "IBulb.h"
// #include "LightSwitchFsm.h"

class ILightSwitchFsm;

class LightStateOff : public ILightState
{
public:
    LightStateOff() {};

    void handleEvent(ILightSwitchFsm* ,EEvent) override;
};

