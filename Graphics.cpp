#include "Graphics.h"

void Graphics::Initialize(int screenWidth, int screenHeight)
{
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;

	InitWindow(_screenWidth, _screenHeight, ScreenTitle);
}

void Graphics::CloseGraphicsWindow()
{
	CloseWindow();
}

bool Graphics::WindowLoop()
{
	BeginDrawing();
	ClearBackground(GRAY);

	if (WindowShouldClose())
	{
		EndDrawing();
		return false;
	}

	return true;
}
