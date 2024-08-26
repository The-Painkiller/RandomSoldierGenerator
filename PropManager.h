#pragma once
#include"Prop.h"
#include<vector>

class PropManager
{
public:
	PropManager() = default;
	PropManager(PropManager&) = delete;
	~PropManager();

	void AddProp(Prop* prop);
	void RemoveProp(const int propIndex);
	Prop *GetProp(int index);
	int GetPropsCount();

private:
	std::vector<Prop*> _props;
};