#include "Algorithm.h"

Algorithm::Algorithm() : curCell(NULL)
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