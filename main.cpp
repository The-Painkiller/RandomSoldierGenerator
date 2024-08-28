#include<iostream>
#include "GameManager.h"
#include"raylib.h"

using namespace std;

int main()
{
	GameManager* gameManager = new GameManager(2, 20);
	gameManager->Initialize();

    InitWindow(800, 450, "raylib [core] example - basic window");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

	gameManager->LogPlayerArmies();
	gameManager->BeginBattle();
}