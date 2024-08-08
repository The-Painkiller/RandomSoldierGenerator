#pragma once
#include "UniqueAttackStyle.h"
class UniqueAttackGuerilla : public UniqueAttackStyle
{
public:
	UniqueAttackGuerilla(int initialDamage) : UniqueAttackStyle(initialDamage) {}

	~UniqueAttackGuerilla() {}

	void UniqueAttack(int& enemyHealth) override;
	GuerillaStyle GetGuerillaStyle();

protected:
	void SetGuerillaStyle(GuerillaStyle style);

private:
	GuerillaStyle _style = GenericGuerilla;
};

