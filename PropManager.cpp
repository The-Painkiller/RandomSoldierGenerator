#include "PropManager.h"

PropManager::PropManager(int initialPropCount)
{
	_initialPropCount = initialPropCount;
}

PropManager::~PropManager()
{
	for (int i = 0; i < _props.size(); i++)
	{
		delete _props[i];
	}

	_props.clear();
}
