#pragma once

#include "ILightState.h"

class ILightSwitchFsm;

class LightStateOneOn : public ILightState
{
public:
    LightStateOneOn() {};

    void handleEvent(ILightSwitchFsm*, EEvent) override;
};
