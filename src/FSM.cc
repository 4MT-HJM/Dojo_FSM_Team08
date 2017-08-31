#include "FSM.h"
#include "ILightState.h"

void LightSwitchFsm::processEvent(const EEvent p_event)
{
    m_currentState->handleEvent(p_event);
}

