#pragma once
#include<iostream>
#include"Player.h"
using namespace std;

class GameLogger
{
public:
	static void LogPlayerArmy(Player& player);

private:
	static const char* GetSoldierTypeName(SoldierType type);
};