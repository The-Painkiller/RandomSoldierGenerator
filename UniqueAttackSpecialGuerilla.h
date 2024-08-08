#pragma once
#include "UniqueAttackGuerilla.h"
class UniqueAttackSpecialGuerilla : public UniqueAttackGuerilla
{
public:
	UniqueAttackSpecialGuerilla(int initialDamage) : UniqueAttackGuerilla(initialDamage)
	{
		SetGuerillaStyle(SpecialOne);
	}

	~UniqueAttackSpecialGuerilla() {}
};

