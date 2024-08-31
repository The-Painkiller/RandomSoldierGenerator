#include "Graphics2D.h"

void Graphics2D::Initialize(GridCoordinates gridSize)
{
	_gridSize = gridSize;
	InitWindow(ScreenWidth, ScreenHeight, "Random Soldier Generator");
	SetTargetFPS(60);

	_cellWidth = ScreenWidth / _gridSize.X;
	_cellHeight = ScreenHeight / _gridSize.Y;

	_camera.rotation = 0.0f;
	_camera.zoom = 1.0f;
}

void Graphics2D::CloseGraphicsWindow()
{
	CloseWindow();
}

bool Graphics2D::WindowLoop()
{
	CheckMouseButtonDown(MOUSE_BUTTON_LEFT);

	CheckMouseScroll();

	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode2D(_camera);

	if (WindowShouldClose())
	{
		EndMode2D();
		EndDrawing();
		return false;
	}

	DrawGrid2D();

	EndMode2D();
	EndDrawing();
	return true;
}

void Graphics2D::DrawGrid2D()
{
	for (int i = 0; i < _gridSize.Y; i++)
	{
		for (int j = 0; j < _gridSize.X; j++)
		{
			GridCoordinates pos = { j, i };
			/*if (_occupiedCells.find(pos) == _occupiedCells.end())
			{
				DrawRectangle(i * _cellWidth, j * _cellHeight, _cellWidth - 1, _cellHeight - 1, LIGHTGRAY);
			}
			else
			{
				DrawRectangle(i * _cellWidth, j * _cellHeight, _cellWidth - 1, _cellHeight - 1, _occupiedCells[pos]);
			}*/
		}
	}
}

void Graphics2D::SetCellData(const GridCoordinates position, Color color)
{
	if (_occupiedCells.find(position) == _occupiedCells.end())
	{
		//_occupiedCells.insert({ position, color });
	}
}

void Graphics2D::CheckMouseScroll()
{
	_mouseWheelScroll = GetMouseWheelMove();
	if (_mouseWheelScroll != 0)
	{
		_mouseWorldPosition = GetScreenToWorld2D(GetMousePosition(), _camera);

		_camera.offset = GetMousePosition();
		_camera.target = _mouseWorldPosition;

		_cameraZoomScaleFactor = 1.0f + (0.25f * fabsf(_mouseWheelScroll));
		if (_mouseWheelScroll < 0) _cameraZoomScaleFactor = 1.0f / _cameraZoomScaleFactor;
		_camera.zoom = Clamp(_camera.zoom * _cameraZoomScaleFactor, 0.125f, 64.0f);
	}
}

void Graphics2D::CheckMouseButtonDown(MouseButton button)
{
	if (IsMouseButtonDown(button))
	{
		_mouseDelta = GetMouseDelta();
		_mouseDelta = Vector2Scale(_mouseDelta, -1.0f / _camera.zoom);
		_camera.target = Vector2Add(_camera.target, _mouseDelta);
	}
}