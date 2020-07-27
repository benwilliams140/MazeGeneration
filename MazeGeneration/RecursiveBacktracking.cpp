#include "RecursiveBacktracking.h"

RecursiveBacktracking::RecursiveBacktracking(MazeCell* _start) : Algorithm(_start)
{

}

bool RecursiveBacktracking::update(Array2D<MazeCell*>& _maze)
{
	if (prevCells.empty()) curCell->visit();
	curCell->update();

	MazeCell* _nextCell = getNextCell(_maze, curCell);
	if (_nextCell)
	{
		curCell->removeWall(_nextCell);

		prevCells.push_back(curCell);
		curCell = _nextCell;
	}
	else
	{
		curCell = prevCells.back();
		prevCells.pop_back();

		if (curCell == startingCell) return false;
	}

	curCell->visit();

	return true;
}