#pragma once
#include "GlobalEnums.h"
#include <vector>

class EventHandler
{
public:
	virtual void HandleEvent(GameEvent type, int args1, int args2) = 0;
};

class Event
{
public:
	Event() = default;
	~Event();
	void Register(EventHandler* handler);
	void Invoke(GameEvent type);
	void Invoke(GameEvent type, int arg1, int arg2);
	
protected:
	std::vector<EventHandler*> _eventHandlers;
	const int NullArg = -1;
};