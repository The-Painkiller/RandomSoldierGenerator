#pragma once
struct GridCoordinates
{
	int X;
	int Y;

	bool operator < (const GridCoordinates& rhs) const
	{
		return this->X < rhs.X || this->Y < rhs.Y;
	}

	bool operator == (const GridCoordinates& rhs) const
	{
		return this->X == rhs.X && this->Y == rhs.Y;
	}
};

enum SoldierType
{
	Sniper = 1,
	GreenBeret = 2,
	Marine = 3,
	Spy = 4,
	None = 5
};

enum GameEvent
{
	GameOver = 1,
	SoldierDeath = 2,
	SoldierHurt = 3
};

enum PlayerSide
{
	NoSide = 0,
	Left = 1,
	Right = 2
};

enum PropType
{
	DudProp = 0,
	HealthBoostType = 1,
	ArmourType = 2,
	AttackBoostType = 3
};

const int ThreadSleepTime = 500;