#pragma once
#include "IBulb.h"
#include <memory>

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

class ILightState;

class LightSwitchFsm
{
public:
    LightSwitchFsm(
        std::shared_ptr<ILightState> p_stateOff,
        std::shared_ptr<ILightState> p_stateOneOn):
        s_stateOff(p_stateOff),
        s_stateOneOn(p_stateOneOn)
    {
        m_currentState=s_stateOff;
    };

    void processEvent(const EEvent);

private:

    std::shared_ptr<ILightState> m_currentState; 
    std::shared_ptr<ILightState> s_stateOff; 
    std::shared_ptr<ILightState> s_stateOneOn; 
};

