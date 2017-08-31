#pragma once
#include "ILightState.h"
#include "IBulb.h"

class LightStateOff : public ILightState
{
public:
    LightStateOff(IBulb& bulb1, IBulb& bulb2):
        m_bulb1(bulb1),
        m_bulb2(bulb2)
    {};

    virtual void handleEvent(EEvent) override;

private:
    IBulb& m_bulb1;
    IBulb& m_bulb2;
};
