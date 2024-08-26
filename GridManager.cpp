#include "GridManager.h"

GridManager::GridManager(const GridCoordinates size)
{
	_gridSize = size;
}

GridManager::~GridManager()
{
	_occupiedPositions.clear();
}

void GridManager::OccupyPosition(const GridCoordinates position)
{
	_occupiedPositions.push_back(position);
}

void GridManager::ClearPositions()
{
	_occupiedPositions.clear();
}

GridCoordinates GridManager::GetGridSize()
{
	return _gridSize;
}

bool GridManager::IsPositionOccupied(const GridCoordinates position)
{
	return std::find_if(_occupiedPositions.begin(), _occupiedPositions.end(), [position](const GridCoordinates& pos) {return pos.X == position.X && pos.Y == position.Y; }) != _occupiedPositions.end();
}