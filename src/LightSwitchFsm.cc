#include "LightSwitchFsm.h"
#include "LightStateOneOn.h"
#include "LightStateOff.h"
#include <memory>
#include <iostream>

std::shared_ptr<ILightState> LightSwitchFsm::s_stateOff = std::make_shared<LightStateOff>();
std::shared_ptr<ILightState> LightSwitchFsm::s_stateOneOn = std::make_shared<LightStateOneOn>();


void LightSwitchFsm::processEvent(const EEvent p_event)
{
    m_currentState->handleEvent(this, p_event);
}

void LightSwitchFsm::turnOnBulb1()
{
	std::cout << "turn on in fsm!\n";
}
std::shared_ptr<ILightState> LightSwitchFsm::getCurrentState()
{
	return m_currentState;
}

void LightSwitchFsm::transiteState(const std::shared_ptr<ILightState> p_state)
{
	m_currentState = p_state;
}



