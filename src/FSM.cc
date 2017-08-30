#include "FSM.h"

void LightStateOff::handleEvent(EEvent p_event) 
{
    if(EEvent::EEventTurnRight == p_event)
    {
        m_bulb1.turnOn();    
    }
}

void LightSwitchFsm::processEvent(const EEvent p_event)
{
    m_currentState->handleEvent(p_event);
}

