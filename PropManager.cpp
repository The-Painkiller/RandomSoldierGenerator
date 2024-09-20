#include "PropManager.h"

PropManager::~PropManager()
{
	for (int i = 0; i < _props.size(); i++)
	{
		delete _props[i];
	}

	_props.clear();
}

void PropManager::AddProp(Prop* prop)
{
	_props.push_back(prop);
}

void PropManager::RemoveProp(const int propIndex)
{
	delete _props[propIndex];
	_props.erase(_props.begin() + propIndex);
}

Prop& PropManager::GetProp(int index)
{
	if (_props[index] != nullptr)
	{
		return *_props[index];
	}
}

int PropManager::GetPropsCount()
{
	return _props.size();
}
