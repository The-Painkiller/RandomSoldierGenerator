#pragma once
#include"Object.h"
#include "PropArmour.h"
#include <memory>

class Soldier : public Object
{
public:
	Soldier(SoldierType type, int initialHealth, int damage, int attackRange, GridCoordinates position);
	virtual ~Soldier() = default;

	virtual void Attack(int& enemyHealth) = 0;
	virtual int GetSpeed() = 0;

	void SetPlayerId(int Id);
	void SetHealth(int health, bool isDamage);
	void SetArmour(const PropArmour& armour);
	void SetDamage(int damage);
	void SetPosition(GridCoordinates position) override;
	GridCoordinates GetPosition() override;

	int GetDefaultHealth();
	int GetHealth();
	int GetDamage();
	int GetParentPlayerId();
	double GetAttackRange();

	SoldierType GetType();

protected:
	void ReduceEnemyHealth(int& enemyHealth);
	int _defaultHealth = 0;

private:
	int _parentPlayerId = -1;
	int _health = 0;
	int _damage = 0;
	double _attackRange = 0;

	SoldierType _type;

	std::unique_ptr<PropArmour> _armour;
};