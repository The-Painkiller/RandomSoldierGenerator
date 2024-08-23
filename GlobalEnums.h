#pragma once
struct GridCoordinates
{
	int X;
	int Y;
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
	GameOver = 1
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