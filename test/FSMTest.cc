#include "gtest/gtest.h"
#include "FSM.h"
#include "BulbMock.h"
//#include <memory>

using namespace testing;

class LightSwitchFsmTestSuite : public Test
{
public:
    LightSwitchFsmTestSuite() : m_lightSwitchFsm(m_bulbMock1, m_bulbMock2)
    {
    }

    StrictMock<BulbMock> m_bulbMock1;
    StrictMock<BulbMock> m_bulbMock2;
    LightSwitchFsm m_lightSwitchFsm;
};

TEST_F(LightSwitchFsmTestSuite, CheckLightInitialStatus)
{    
    EXPECT_EQ(ELightStates::EStateOff, m_lightSwitchFsm.getStatus());
    
}

TEST_F(LightSwitchFsmTestSuite, CheckOneLightOn)
{
    EXPECT_CALL(m_bulbMock1, turnOn()); 
    m_lightSwitchFsm.handleEvent(EEvent::EEventTurnRight);
    EXPECT_EQ(ELightStates::EStateOneOn, m_lightSwitchFsm.getStatus());    
}

TEST_F(LightSwitchFsmTestSuite, CheckTwoLightsOn)
{
    EXPECT_CALL(m_bulbMock1, turnOn());
    EXPECT_CALL(m_bulbMock2, turnOn());
    m_lightSwitchFsm.handleEvent(EEvent::EEventTurnRight);
    m_lightSwitchFsm.handleEvent(EEvent::EEventTurnRight);
    EXPECT_EQ(ELightStates::EstateAllOn, m_lightSwitchFsm.getStatus());    
}

TEST_F(LightSwitchFsmTestSuite, CheckOneLightOff)
{
    EXPECT_CALL(m_bulbMock1, turnOn()); 
    EXPECT_CALL(m_bulbMock1, turnOff()); 
    m_lightSwitchFsm.handleEvent(EEvent::EEventTurnRight);
    m_lightSwitchFsm.handleEvent(EEvent::EEventTurnLeft);
    EXPECT_EQ(ELightStates::EStateOff, m_lightSwitchFsm.getStatus());    
}
