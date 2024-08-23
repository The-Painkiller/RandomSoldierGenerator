#pragma once
#include "GlobalEnums.h"
#include <vector>

class EventHandler
{
public:
	virtual void HandleEvent(GameEvent type) = 0;
};

class Event
{
public:
	Event() = default;
	~Event();
	void Register(EventHandler* handler);
	void Invoke(GameEvent type);
	
protected:
	std::vector<EventHandler*> _eventHandlers;
};