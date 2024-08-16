#include<iostream>
#include "GameManager.h"

using namespace std;

int main()
{
	GameManager* gameManager = new GameManager(2, 20);
	gameManager->Initialize();

	gameManager->LogPlayerArmies();
	//for (int i = 0; i < gameManager->GetCurrentPlayerCount(); i++)
	//{
	//	
	//	/*printf("Player %d", i);
	//	printf("\n");
	//	for (int j = 0; j < gameManager->GetPlayer(i).GetArmySize(); j++)
	//	{
	//		printf("%d",gameManager->GetPlayer(i).GetSoldier(j).GetType());
	//		printf("\n");
	//	}
	//	printf("\n");
	//	printf("\n");*/
	//}

	//gameManager->BeginBattle();
}