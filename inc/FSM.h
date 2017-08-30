#pragma once
#include "IBulb.h"

enum class ELightStates
{
    EStateOff,
    EStateOneOn,
    EStateAllOn
};

enum class EEvent
{
    EEventTurnRight,
    EEventTurnLeft
};

class LightSwitchFsm
{
public:
    LightSwitchFsm(IBulb& bulb1, IBulb& bulb2):
        m_status(ELightStates::EStateOff),
        m_bulb1(bulb1),
        m_bulb2(bulb2) 
    {};

    ELightStates getStatus() const;
    void handleEvent(const EEvent);

private:
    ELightStates m_status; 
    IBulb& m_bulb1;
    IBulb& m_bulb2;
};

