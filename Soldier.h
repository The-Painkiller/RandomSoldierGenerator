#pragma once
#include"GlobalEnums.h"

class Soldier
{
public:
	Soldier(SoldierType type, int initialHealth, int damage, int attackRange, GridCoordinates position);
	~Soldier() {}

	virtual void Attack(int& enemyHealth) = 0;

	void SetPlayerId(int Id);
	void SetHealth(int health);
	void SetPosition(GridCoordinates position);
	GridCoordinates GetPosition();

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
	GridCoordinates _position;
};