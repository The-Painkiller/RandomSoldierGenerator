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

enum GameState
{
	Battle = 1,
	Finished = 2
};