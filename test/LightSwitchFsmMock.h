// #include "BulbMock.h"
// #include "LightState.h"
#include "LightSwitchFsm.h"

using namespace std;
using namespace testing;

class ILightState;

class LightSwitchFsmMock : public LightSwitchFsm
{
public:
	MOCK_METHOD1(transiteState, void(std::shared_ptr<ILightState>));
	MOCK_METHOD0(turnOnBulb1, void());
};