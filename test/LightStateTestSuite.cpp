#include "gtest/gtest.h"
#include "BulbMock.h"
#include "LightStateOneOn.h"
#include "LightStateOff.h"
#include "LightSwitchFsmMock.h"

using namespace std;
using namespace testing;

class LightStateTestSuite : public Test
{
public:
	LightStateOff m_lightStateOff{};
	std::shared_ptr<ILightState> m_currentState = LightSwitchFsm::s_stateOff;
	LightSwitchFsmMock m_lightSwitchFsmMock{};
};

TEST_F(LightStateTestSuite, ShouldTurnOnBulb1_WhenStateOff_EventTurnRight)
{
	EXPECT_CALL(m_lightSwitchFsmMock, turnOnBulb1());
	EXPECT_CALL(m_lightSwitchFsmMock, transiteState(LightSwitchFsm::s_stateOneOn));
	m_lightStateOff.handleEvent(&m_lightSwitchFsmMock, EEvent::EEventTurnRight);
};



