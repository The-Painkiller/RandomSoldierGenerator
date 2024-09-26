#pragma once
#include "GlobalEnums.h"
#include <vector>
#include <memory>

class EventHandler
{
public:
	virtual void HandleEvent(GameEvent type, const GridCoordinates arg1, const int arg2) = 0;
	virtual void HandleEvent(GameEvent type, const GridCoordinates prevPos, const GridCoordinates newPos, const int playerID) = 0;
};

class Event
{
public:
	Event() = default;
	~Event();
	void Register(EventHandler* handler);
	void Invoke(GameEvent type);
	void Invoke(GameEvent type, const GridCoordinates arg1, const int arg2);
	void Invoke(GameEvent type, const GridCoordinates prevPos, const GridCoordinates newPos, const int playerID);
	
	static const int NullIntArg = -1;
	static GridCoordinates NullGridArg;
	
protected:
	std::vector<std::unique_ptr<EventHandler>> _eventHandlers;
};