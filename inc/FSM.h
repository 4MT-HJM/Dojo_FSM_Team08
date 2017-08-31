#pragma once
#include "IBulb.h"
#include "event.h"

#include <memory>
#include <iostream>

class ILightState;

class LightSwitchFsm
{
public:
    LightSwitchFsm()
    {
        m_currentState = s_stateOff;
    }

    void processEvent(const EEvent);
    std::shared_ptr<ILightState> getCurrentState();
    virtual void transiteState(std::shared_ptr<ILightState>);
    void turnOn()
    {
    	std::cout << "turn on in fsm!\n";
    }

    static std::shared_ptr<ILightState> s_stateOff;
    static std::shared_ptr<ILightState> s_stateOneOn;
private:
    std::shared_ptr<ILightState> m_currentState;
};

