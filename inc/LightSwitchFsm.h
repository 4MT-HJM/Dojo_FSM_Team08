#pragma once

#include <memory>

#include "ILightSwitchFsm.h"
#include "IBulb.h"
#include "event.h"

class ILightState;

class LightSwitchFsm : public ILightSwitchFsm
{
public:
    LightSwitchFsm()
    {
        m_currentState = s_stateOff;
    }

    void processEvent(const EEvent);
    std::shared_ptr<ILightState> getCurrentState();
    virtual void transiteState(std::shared_ptr<ILightState>);
    void turnOnBulb1();

    static std::shared_ptr<ILightState> s_stateOff;
    static std::shared_ptr<ILightState> s_stateOneOn;
private:
    std::shared_ptr<ILightState> m_currentState;
};

