#pragma once
#include"Prop.h"
#include<vector>
#include <map>
class PropManager
{
public:
	PropManager() = default;
	PropManager(PropManager&) = delete;
	~PropManager();

	void AddProp(Prop* prop, int propKey);
	void RemoveProp(const int propKey);

private:
	std::map<int, Prop*> _props;
};

