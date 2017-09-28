#pragma once

class ILightState;

class ILightSwitchFsm
{
public:
	virtual ~ILightSwitchFsm() = default;
    virtual void transiteState(std::shared_ptr<ILightState>) = 0;
    virtual void turnOnBulb1() = 0;	
};
