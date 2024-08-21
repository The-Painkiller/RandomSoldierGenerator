#include "PropManager.h"

PropManager::~PropManager()
{
	for (int i = 0; i < _props.size(); i++)
	{
		delete _props[i];
	}

	_props.clear();
}

void PropManager::AddProp(Prop* prop, int propKey)
{
	_props.insert({propKey, prop});
}

void PropManager::RemoveProp(const int propKey)
{
	_props.erase(propKey);
}
