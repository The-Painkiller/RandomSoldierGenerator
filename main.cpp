#include<iostream>
#include "GameManager.h"

using namespace std;

int main()
{
	GameManager* gameManager = new GameManager(2, 20);
	gameManager->Initialize();

	gameManager->LogPlayerArmies();
	gameManager->BeginBattle();
}