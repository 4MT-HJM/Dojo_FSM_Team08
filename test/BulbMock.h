#pragma once
#include "gmock/gmock.h"
#include "IBulb.h"
#include "FSM.h"

class BulbMock : public IBulb
{
public:
    MOCK_METHOD0(turnOn, void());
    MOCK_METHOD0(turnOff, void());
};

