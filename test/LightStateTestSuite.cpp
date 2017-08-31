#include "gtest/gtest.h"
#include "BulbMock.h"
#include "LightState.h"
#include "FSM.h"

using namespace std;
using namespace testing;

class FsmMock : public LightSwitchFsm
{
public:
	FsmMock(){}
	MOCK_METHOD1(transiteState, void(std::shared_ptr<ILightState>));
};

class LightStateTestSuite : public Test
{
public:

	LightStateOff m_lightStateOff{};
	std::shared_ptr<ILightState> m_currentState = LightSwitchFsm::s_stateOff;
};

TEST_F(LightStateTestSuite, ShouldTurnOnBulb1_WhenStateOff_EventTurnRight)
{
	//EXPECT_CALL(m_bulbMock1, turnOn());
	m_lightStateOff.handleEvent(EEvent::EEventTurnRight, m_currentState);
    EXPECT_EQ(LightSwitchFsm::s_stateOneOn, m_currentState);
};
