#pragma once
#include"GlobalEnums.h"
#include "Event.h"
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
	Soldier(SoldierType type, int initialHealth, int commonDamage, int attackRange, GridCoordinates position);
	~Soldier() {}

	virtual void Attack(int& enemyHealth) = 0;
	virtual void SpecialAttack(int& enemyHealth) = 0;

	void RegisterEventHandler(EventHandler* handler);
	void SetPlayerId(int Id);
	void SetHealth(int health);
	void SetPosition(GridCoordinates position);
	GridCoordinates GetPosition();

	int GetHealth();
	int GetCommonDamage();
	int GetParentPlayerId();
	double GetAttackRange();

	SoldierType GetType();

protected:
	void ReduceEnemyHealth(int& enemyHealth);

private:
	int _parentPlayerId = -1;
	int _health = 0;
	int _commonDamage = 0;
	double _attackRange = 0;

	SoldierType _type;
	GridCoordinates _position;
	EventHandler* _eventHandler;
};