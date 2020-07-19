#include "Algorithm.h"

Algorithm::Algorithm(MazeCell* _start) : curCell(_start), startingCell(_start)
{

}

bool Algorithm::update(Array2D<MazeCell*>& _maze)
{
	if (!curCell)
	{
		curCell = _maze[0][0];
	}
	else
	{
		int _nextCol = curCell->getCol() + 1;
		int _nextRow = curCell->getRow();

		if (_nextCol >= _maze.getCols())
		{
			_nextCol = 0;
			++_nextRow;
		}

		if (_maze.inBounds(_nextCol, _nextRow)) curCell = _maze[_nextCol][_nextRow];
		else curCell = NULL;
	}

	if (curCell)
	{
		curCell->setColor(sf::Color::Red);
		return true;
	}
	
	return false;
}

MazeCell* Algorithm::getNextCell(Array2D<MazeCell*>& _maze, MazeCell* _curCell)
{
	int _nextCol, _nextRow;
	_nextCol = _nextRow = -1;

	if (!hasAdjacentCells(_maze, _curCell)) return NULL;

	while (!_maze.inBounds(_nextCol, _nextRow))
	{
		int _wall = rand() % 4;
		_nextCol = _curCell->getCol() + (int)sin(_wall * M_PI_2);
		_nextRow = _curCell->getRow() + (int)sin(_wall * M_PI_2 - M_PI_2);

		if (_maze.inBounds(_nextCol, _nextRow) && _maze[_nextCol][_nextRow]->isVisited()) _nextCol = _nextRow = -1;
	}

	return _maze[_nextCol][_nextRow];
}

bool Algorithm::hasAdjacentCells(Array2D<MazeCell*>& _maze, MazeCell* _curCell)
{
	bool hasCells = false;
	for (int i = 0; i < 4; ++i)
	{
		int _nextCol = _curCell->getCol() + (int)sin(i * M_PI_2);
		int _nextRow = _curCell->getRow() + (int)sin(i * M_PI_2 - M_PI_2);

		if (!hasCells && _maze.inBounds(_nextCol, _nextRow) && !_maze[_nextCol][_nextRow]->isVisited()) hasCells = true;
	}

	return hasCells;
}