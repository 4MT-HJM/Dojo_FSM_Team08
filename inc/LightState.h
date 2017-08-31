#pragma once
#include "ILightState.h"
#include "IBulb.h"
#include "FSM.h"

class LightStateOff : public ILightState
{
public:
    LightStateOff() {};

    virtual void handleEvent(EEvent, std::shared_ptr<ILightState>&) override;
};

class LightStateOneOn : public ILightState
{
public:
    LightStateOneOn() {};

    virtual void handleEvent(EEvent, std::shared_ptr<ILightState>&) override;
};
