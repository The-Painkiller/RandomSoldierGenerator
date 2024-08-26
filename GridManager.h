#pragma once
#include"GlobalEnums.h"
#include <vector>
class GridManager
{
public:
	GridManager(const GridCoordinates size);
	GridManager() = delete;
	~GridManager();

	void OccupyPosition(const GridCoordinates position);
	void ClearPositions();
	GridCoordinates GetGridSize();
	bool IsPositionOccupied(const GridCoordinates position);

private:
	GridCoordinates _gridSize;
	std::vector<GridCoordinates> _occupiedPositions;
};

