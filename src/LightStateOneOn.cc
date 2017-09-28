#include "LightStateOneOn.h"
#include "event.h"
#include "ILightSwitchFsm.h"


void LightStateOneOn::handleEvent(ILightSwitchFsm* p_lightSwitchFsm, EEvent p_event)
{
    if(EEvent::EEventTurnRight == p_event)
    {
    	// p_currentState = LightSwitchFsm::s_stateOff;
    }
}
