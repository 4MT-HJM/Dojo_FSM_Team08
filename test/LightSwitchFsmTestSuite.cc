#include "gtest/gtest.h"
#include "LightSwitchFsm.h"
#include "BulbMock.h"
#include "StateMock.h"
#include "state.h"
#include "ILightState.h"

using namespace std;
using namespace testing;

class LightSwitchFsmTestSuite : public Test
{
public:
    LightSwitchFsmTestSuite()
    {
    }

    StrictMock<BulbMock> m_bulbMock1;
    StrictMock<BulbMock> m_bulbMock2;
    //shared_ptr<StateMock> m_stateOffMock = make_shared<StrictMock<StateMock>>();
    //shared_ptr<StateMock> m_stateOneOnMock = make_shared<StrictMock<StateMock>>();
    LightSwitchFsm m_lightSwitchFsm{};
};

TEST_F(LightSwitchFsmTestSuite, InjectEventIntoCurrentState_WhenStateoff)
{
    EXPECT_EQ(LightSwitchFsm::s_stateOff, m_lightSwitchFsm.getCurrentState());
    m_lightSwitchFsm.processEvent(EEvent::EEventTurnRight);
}

