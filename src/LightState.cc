#include "LightState.h"
#include "event.h"
#include <iostream>

std::function<void()> action1 = []() { std::cout << "turn on!\n"; };
//std::function<void()> action2 = &LightSwitchFsm::turnOn;

void LightStateOff::handleEvent(EEvent p_event, std::shared_ptr<ILightState>& p_currentState)
{
    if(EEvent::EEventTurnRight == p_event)
    {
    	p_currentState = LightSwitchFsm::s_stateOneOn;
    	action1();
    	//action2();
    }
}

void LightStateOneOn::handleEvent(EEvent p_event, std::shared_ptr<ILightState>& p_currentState)
{
    if(EEvent::EEventTurnRight == p_event)
    {
    	p_currentState = LightSwitchFsm::s_stateOff;
    }
}
