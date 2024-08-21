#pragma once
#include"Prop.h"
#include<vector>
class PropManager
{
public:
	PropManager(int initialPropCount);
	PropManager() = delete;
	~PropManager();

	void AddProp();

private:
	int _initialPropCount;
	std::vector<Prop*> _props;
};

