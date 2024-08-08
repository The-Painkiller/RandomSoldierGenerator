#include "UniqueAttackGuerilla.h"

void UniqueAttackGuerilla::UniqueAttack(int& enemyHealth)
{
	ReduceEnemyHealthWithUniqueAttack(enemyHealth);
}

GuerillaStyle UniqueAttackGuerilla::GetGuerillaStyle()
{
	return _style;
}

void UniqueAttackGuerilla::SetGuerillaStyle(GuerillaStyle style)
{
	_style = style;
}
