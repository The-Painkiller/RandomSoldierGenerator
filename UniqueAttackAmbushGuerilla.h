#pragma once
#include "UniqueAttackGuerilla.h"
class UniqueAttackAmbushGuerilla : public UniqueAttackGuerilla
{
public:
	UniqueAttackAmbushGuerilla(int initialDamage) : UniqueAttackGuerilla(initialDamage)
	{
		SetGuerillaStyle(Ambush);
	}
	
	~UniqueAttackAmbushGuerilla() {}
};

