#pragma once
#include"UniqueAttackStyle.h"

class UniqueAttackSnipe : public UniqueAttackStyle
{
public:
	UniqueAttackSnipe(int initialDamage) : UniqueAttackStyle(initialDamage)
	{}
	~UniqueAttackSnipe() {}

	void UniqueAttack(int& enemyHealth) override;
};

