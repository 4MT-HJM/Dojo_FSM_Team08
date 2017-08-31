#include "FSM.h"
#include "LightState.h"
#include <memory>

std::shared_ptr<ILightState> LightSwitchFsm::s_stateOff = std::make_shared<LightStateOff>();
std::shared_ptr<ILightState> LightSwitchFsm::s_stateOneOn = std::make_shared<LightStateOneOn>();


void LightSwitchFsm::processEvent(const EEvent p_event)
{
    m_currentState->handleEvent(p_event, m_currentState);
}


std::shared_ptr<ILightState> LightSwitchFsm::getCurrentState()
{
	return m_currentState;
}

void LightSwitchFsm::transiteState(const std::shared_ptr<ILightState> p_state)
{
	m_currentState=p_state;
}



