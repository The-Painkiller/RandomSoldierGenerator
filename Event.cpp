#include "Event.h"

Event::~Event()
{
	for (int i = 0; i < _eventHandlers.size(); i++)
	{
		delete _eventHandlers[i];
	}

	_eventHandlers.clear();
}

void Event::Register(EventHandler* handler)
{
	_eventHandlers.push_back(handler);
}

void Event::Invoke(GameEvent type)
{
	for (int i = 0; i < _eventHandlers.size(); i++)
	{
		_eventHandlers[i]->HandleEvent(type);
	}
}
