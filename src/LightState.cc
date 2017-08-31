#include "LightState.h"

void LightStateOff::handleEvent(EEvent p_event)
{
    if(EEvent::EEventTurnRight == p_event)
    {
        m_bulb1.turnOn();
    }
}
