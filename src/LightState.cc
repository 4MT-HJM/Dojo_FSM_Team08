#include "LightState.h"
#include "event.h"

void LightStateOff::handleEvent(EEvent p_event, std::shared_ptr<ILightState>& p_currentState)
{
    if(EEvent::EEventTurnRight == p_event)
    {
    	p_currentState = LightSwitchFsm::s_stateOneOn;
    }
}

void LightStateOneOn::handleEvent(EEvent p_event, std::shared_ptr<ILightState>& p_currentState)
{
    if(EEvent::EEventTurnRight == p_event)
    {
    	p_currentState = LightSwitchFsm::s_stateOff;
    }
}
