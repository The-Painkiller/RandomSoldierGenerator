#pragma once

enum SoldierType
{
	None,
	Sniper,
	GreenBeret,
	Marine,
	Spy
};

class Soldier
{
public:
	Soldier(SoldierType type, int initialHealth, int commonDamage);
	~Soldier() {}

	virtual void Attack(int& enemyHealth) = 0;

	void SetDamage(int health);
	int GetHealth();
	SoldierType GetType();
	int GetCommonDamage();

protected:
	void ReduceEnemyHealth(int& enemyHealth);

private:
	int _health;
	int _commonDamage;
	SoldierType _type;
};