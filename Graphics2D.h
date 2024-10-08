#pragma once
#include "GlobalEnums.h"
#include <raylib.h>
#include <raymath.h>
#include<vector>

struct GridRect
{
public:
	Rectangle Rect;
	Color RectColor;
};

class Graphics2D
{
public:
	Graphics2D() = default;
	~Graphics2D();
	bool ShouldGraphicsWindowClose();
	void Initialize(GridCoordinates gridSize);
	void CloseGraphicsWindow();
	void WindowLoop();
	void CheckMouseScroll();
	void CheckMouseButtonDown(MouseButton button);
	void DrawGrid2D();
	void SetCellData(const GridCoordinates& cellPosition, Color color);
	void ResetCellData();
	void DrawObject(const GridCoordinates& cellPosition, Color color);
	void DrawObjects();
	void DrawGraphicsText(const char* text);

private:
	const int ScreenWidth = 1000;
	const int ScreenHeight = 1000;
	
	int _cellWidth = 0;
	int _cellHeight = 0;
	
	float _mouseWheelScroll = 0.0f;
	float _cameraZoomScaleFactor = 0.0f;

	Vector2 _mouseDelta = Vector2();
	Vector2 _mouseWorldPosition = Vector2();

	GridCoordinates _gridSize = {};
	Camera2D _camera = {};
	std::vector<std::vector<GridRect>> _occupiedCells;
};