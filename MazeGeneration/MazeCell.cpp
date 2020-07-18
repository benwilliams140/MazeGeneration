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
	rect.setFillColor(sf::Color(146, 146, 146));
}

MazeCell::~MazeCell()
{

}

void MazeCell::update()
{
	rect.setFillColor(sf::Color::Red);
}

void MazeCell::render(Window* _window)
{
	_window->render(rect);

	for (int i = 0; i < 4; ++i)
		walls[i]->render(_window);
}

int MazeCell::getCol()
{
	return col;
}

int MazeCell::getRow()
{
	return row;
}

void MazeCell::setColor(sf::Color _color)
{
	rect.setFillColor(_color);
}