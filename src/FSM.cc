#include "FSM.h"

ELightStates LightSwitchFsm::getStatus() const
{
    return m_status;
}

void LightSwitchFsm::handleEvent(const EEvent p_event)
{
    if(ELightStates::EStateOff == m_status)
    {
        m_bulb1.turnOn();
        m_status = ELightStates::EStateOneOn;
    }
    else if(ELightStates::EStateOneOn == m_status)
    {
        if (p_event == EEvent::EEventTurnLeft)
        {
            m_bulb1.turnOff();
            m_status = ELightStates::EStateOff;
        }
        else
        {
            m_bulb2.turnOn();
            m_status = ELightStates::EStateAllOn;
        }
    }

}
