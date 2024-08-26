#pragma once
#include<iostream>
#include"Player.h"
#include "PropArmour.h"
#include "PropAttackBoost.h"
#include "PropHealthBoost.h"

using namespace std;

class GameLogger
{
public:
	static void LogPlayerArmy(Player& player);
	static void LogAttack(int attackingPlayerId, int attackingSoldierId, int defendingPlayerId, int defendingSoldierId, int defendingSoldierHealth);
	static void LogDeath(int dyingSoldierId, int dyingSoldierPlayerId);
	static void LogResult(int playerId, bool isVictor);
	static void LogText(const char* text);
	static void LogPropConsumption(int playerId, int soldierId, Prop* prop);

private:
	static const char* GetSoldierTypeName(SoldierType type);
	static const char* GetPropTypeName(PropType type);
};