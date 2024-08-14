#pragma once
#include "GlobalEnums.h"
class EventHandler
{
public:
	virtual void HandleEvent(int eventType) = 0;
};