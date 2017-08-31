#pragma once

#include "ILightState.h"

class StateMock : public ILightState
{
public:
   MOCK_METHOD1(handleEvent,void(EEvent));
};
