#include "SoldierSpy.h"

void SoldierSpy::Attack(int& enemHealth)
{
	ReduceEnemyHealth(enemHealth);
}

int SoldierSpy::GetSpeed()
{
	return Speed;
}