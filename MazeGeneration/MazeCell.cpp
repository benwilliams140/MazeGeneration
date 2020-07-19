#include "MazeCell.h"

MazeCell::MazeCell(int _size, int _col, int _row) : visited(false), col(_col), row(_row)
{
	int _curX, _curY, _nextX, _nextY;
	_curX = _col * _size;
	_curY = _nextY =  _row * _size;

	for (int i = 0; i < 4; ++i)
	{
		int _deltaX = (int)sin(i * M_PI_2 + M_PI_2);
		int _deltaY = (int)sin(i * M_PI_2);

		_nextX = _curX + _deltaX * _size;
		_nextY = _curY + _deltaY * _size;
		
		walls[i] = new MazeWall(_curX, _curY, _nextX, _nextY);
		
		_curX = _nextX;
		_curY = _nextY;
	}

	rect.setSize(sf::Vector2f(_size, _size));
	rect.setOrigin(sf::Vector2f(0, 0));
	rect.setPosition(sf::Vector2f(_col * _size, _row * _size));
	rect.setFillColor(INITIAL_COLOR);
}

MazeCell::~MazeCell()
{

}

void MazeCell::update()
{
	if (visited) rect.setFillColor(VISITED_COLOR);
}

void MazeCell::render(Window* _window)
{
	_window->render(rect);

	for (int i = 0; i < 4; ++i)
	{
		if(walls[i]) walls[i]->render(_window);
	}
}

void MazeCell::removeWall(MazeCell* _nextCell)
{
	MazeWall* _wall;
	int _index = 0;

	if (_nextCell->getRow() < row) // top
		_index = 0;
	else if (_nextCell->getCol() > col) // right
		_index = 1;
	else if (_nextCell->getRow() > row) // bottom
		_index = 2;
	else if (_nextCell->getCol() < col) // left
		_index = 3;

	_wall = walls[_index];
	walls[_index] = NULL;
	delete _wall;

	if (_nextCell->getWall((_index + 2) % 4))
		_nextCell->removeWall(this);
}

int MazeCell::getCol()
{
	return col;
}

int MazeCell::getRow()
{
	return row;
}

MazeWall* MazeCell::getWall(int _index)
{
	return walls[_index];
}

void MazeCell::setColor(sf::Color _color)
{
	rect.setFillColor(_color);
}

bool MazeCell::isVisited()
{
	return visited;
}

void MazeCell::visit()
{
	visited = true;
	rect.setFillColor(CUR_CELL_COLOR);
}