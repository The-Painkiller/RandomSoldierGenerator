#pragma once
#include"Object.h"

class Soldier : public Object
{
public:
	Soldier(SoldierType type, int initialHealth, int damage, int attackRange, GridCoordinates position);
	~Soldier() {}

	virtual void Attack(int& enemyHealth) = 0;
	virtual int GetSpeed() = 0;

	void SetPlayerId(int Id);
	void SetHealth(int health);
	void SetPosition(GridCoordinates position) override;
	GridCoordinates GetPosition() override;

	int GetHealth();
	int GetDamage();
	int GetParentPlayerId();
	double GetAttackRange();

	SoldierType GetType();

protected:
	void ReduceEnemyHealth(int& enemyHealth);

private:
	int _parentPlayerId = -1;
	int _health = 0;
	int _damage = 0;
	double _attackRange = 0;

	SoldierType _type;
};