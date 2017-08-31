#include "gtest/gtest.h"
#include "FSM.h"
#include "BulbMock.h"
#include "StateMock.h"
#include "state.h"
#include "ILightState.h"

using namespace std;
using namespace testing;

class LightSwitchFsmTestSuite : public Test
{
public:
    LightSwitchFsmTestSuite() : m_lightSwitchFsm(m_stateOffMock, m_stateOneOnMock)
    {
    }

    StrictMock<BulbMock> m_bulbMock1;
    StrictMock<BulbMock> m_bulbMock2;
    shared_ptr<StateMock> m_stateOffMock = make_shared<StrictMock<StateMock>>();
    shared_ptr<StateMock> m_stateOneOnMock = make_shared<StrictMock<StateMock>>();
    LightSwitchFsm m_lightSwitchFsm;
};

TEST_F(LightSwitchFsmTestSuite, InjectEventIntoCurrentState_WhenStateoff)
{
    EXPECT_CALL(*m_stateOffMock, handleEvent(EEvent::EEventTurnRight));
    m_lightSwitchFsm.processEvent(EEvent::EEventTurnRight);

    EXPECT_EQ(LightSwitchFsm::s_stateOneOn, m_lightSwitchFsm.getCurrentState());
}

