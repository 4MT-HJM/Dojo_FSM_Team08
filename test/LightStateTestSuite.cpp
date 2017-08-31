#include "gtest/gtest.h"
#include "BulbMock.h"
#include "LightState.h"

using namespace std;
using namespace testing;

class LightStateTestSuite :public Test
{
public:
	StrictMock<BulbMock> m_bulbMock1;
	StrictMock<BulbMock> m_bulbMock2;
	LightStateOff m_lightStateOff{m_bulbMock1,m_bulbMock2};
};

TEST_F(LightStateTestSuite, ShouldTurnOnBulb1_WhenStateOff_EventTurnRight)
{
	EXPECT_CALL(m_bulbMock1, turnOn());
	m_lightStateOff.handleEvent(EEvent::EEventTurnRight);
};
