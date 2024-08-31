#pragma once
#include "raylib.h"
#include "GlobalEnums.h"

class Graphics
{
public:
	Graphics() = default;
	~Graphics() = default;

	void Initialize(int screenWidth, int screenHeight);
	void CloseGraphicsWindow();
	bool WindowLoop();

private:
	GridCoordinates _gridSize = {};
	int _screenWidth = 0;
	int _screenHeight = 0;

	const char* ScreenTitle = "Random Battle Simulator";
};

