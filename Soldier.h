#pragma once
#include"GlobalEnums.h"
enum SoldierType
{
	Sniper = 1,
	GreenBeret = 2,
	Marine = 3,
	Spy = 4,
	None = 5
};

class Soldier
{
public:
	Soldier(SoldierType type, int initialHealth, int commonDamage, GridCoordinates position);
	~Soldier() {}

	virtual void Attack(int& enemyHealth) = 0;

	void SetDamage(int health);
	void SetPosition(GridCoordinates position);
	GridCoordinates GetPosition();

	int GetHealth();
	int GetCommonDamage();

	SoldierType GetType();

protected:
	void ReduceEnemyHealth(int& enemyHealth);

private:
	int _health = 0;
	int _commonDamage = 0;
	SoldierType _type;
	GridCoordinates _position;
};