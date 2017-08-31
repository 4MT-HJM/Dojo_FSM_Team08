#include "FSM.h"
#include "LightState.h"
#include <memory>

static LightSwitchFsm::s_stateOff   = std::make_shared<LightStateOff>();
static LightSwitchFsm::s_stateOneOn = std::make_shared<LightStateOn>();

void LightSwitchFsm::processEvent(const EEvent p_event)
{
    m_currentState->handleEvent(p_event);
}


std::shared_ptr<ILightState> LightSwitchFsm::getCurrentState()
{
	return m_currentState;
}
