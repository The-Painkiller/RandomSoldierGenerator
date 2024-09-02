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

	GridRect rect;
	rect.RectColor = LIGHTGRAY;
	_occupiedCells.assign(_gridSize.X, std::vector<GridRect>(_gridSize.Y, rect));
	for (int i = 0; i < _gridSize.Y; i++)
	{
		for (int j = 0; j < _gridSize.X; j++)
		{
			_occupiedCells[j][i].Rect.x = i * _cellWidth;
			_occupiedCells[j][i].Rect.y = j * _cellHeight;
			_occupiedCells[j][i].Rect.width = _cellWidth - 1;
			_occupiedCells[j][i].Rect.height = _cellHeight - 1;
			_occupiedCells[j][i].RectColor = LIGHTGRAY;
		}
	}
}

Graphics2D::~Graphics2D()
{
	_gridSize = {};
	_camera = {};
	_occupiedCells.clear();
}

bool Graphics2D::ShouldGraphicsWindowClose()
{
	return WindowShouldClose();
}

void Graphics2D::CloseGraphicsWindow()
{
	CloseWindow();
}

void Graphics2D::WindowLoop()
{
	CheckMouseButtonDown(MOUSE_BUTTON_LEFT);

	CheckMouseScroll();

	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode2D(_camera);

	DrawGrid2D();

	EndMode2D();
	EndDrawing();
}

void Graphics2D::DrawGrid2D()
{
	for (int i = 0; i < _gridSize.Y; i++)
	{
		for (int j = 0; j < _gridSize.X; j++)
		{
			DrawRectangleRec(_occupiedCells[i][j].Rect, _occupiedCells[i][j].RectColor);
		}
	}
}

void Graphics2D::SetCellData(const GridCoordinates& position, Color color)
{
	_occupiedCells[position.X][position.Y].RectColor = color;
}

void Graphics2D::ResetCellData()
{
	for (int i = 0; i < _gridSize.Y; i++)
	{
		for (int j = 0; j < _gridSize.X; j++)
		{
			_occupiedCells[j][i].RectColor = LIGHTGRAY;
		}
	}
}

void Graphics2D::DrawObject(int posX, int posY, Color color)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode2D(_camera);
	_occupiedCells[posX][posY].RectColor = color;
	DrawGrid2D();
	EndMode2D();
	EndDrawing();
}

void Graphics2D::DrawGraphicsText(const char* text)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode2D(_camera);
	DrawText(text, ScreenWidth / 2, ScreenHeight / 2, 50, BLACK);
	EndMode2D();
	EndDrawing();
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