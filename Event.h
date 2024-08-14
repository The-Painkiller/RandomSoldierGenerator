#pragma once
class Event
{
};

class EventHandler
{
public:
	template<typename T>
	virtual void HandleEvent(int eventType, T arg1) = 0;
};