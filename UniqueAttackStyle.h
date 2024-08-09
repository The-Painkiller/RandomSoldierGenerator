#pragma once

enum UniqueAttackType
{
	Snipe,
	Guerilla
};

enum GuerillaStyle
{
	GenericGuerilla,
	SpecialOne,
	Ambush
};

class UniqueAttackStyle
{
public:
	UniqueAttackStyle(int initialDamage);
	~UniqueAttackStyle() {}

	virtual void UniqueAttack(int& enemyHealth) = 0;
	int GetUniqueDamage();

protected:
	void ReduceEnemyHealthWithUniqueAttack(int& enemyHealth);

private:
	int _damage;
};