#pragma once
#include "UniqueAttackStyle.h"
class UniqueAttackGuerilla : public UniqueAttackStyle
{
public:
	UniqueAttackGuerilla(int initialDamage) : UniqueAttackStyle(initialDamage) {}

	~UniqueAttackGuerilla() {}

	GuerillaStyle GetGuerillaStyle();

protected:
	void UniqueAttack(int& enemyHealth) override;
	void SetGuerillaStyle(GuerillaStyle style);

private:
	GuerillaStyle _style = GenericGuerilla;
};

