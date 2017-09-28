#include "LightStateOff.h"
#include "event.h"
#include "LightSwitchFsm.h"

void LightStateOff::handleEvent(ILightSwitchFsm* p_lightSwitchFsm, EEvent p_event)
{
    if(EEvent::EEventTurnRight == p_event)
    {
    	p_lightSwitchFsm->turnOnBulb1();
		p_lightSwitchFsm->transiteState(LightSwitchFsm::s_stateOneOn);
    }
}
