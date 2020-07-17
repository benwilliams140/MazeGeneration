#include "Maze.h"

Maze::Maze()
{
	for (int _col = 0; _col < size; ++_col)
	{
		for (int _row = 0; _row < size; ++_row)
		{
			maze[_col][_row] = new Box(boxSize, _col, _row);
		}
	}
}

Maze::~Maze()
{

}

void Maze::update()
{
	for (int _col = 0; _col < size; ++_col)
	{
		for (int _row = 0; _row < size; ++_row)
		{
			if (maze[_col][_row]) maze[_col][_row]->update();
		}
	}
}

void Maze::render(Window* _window)
{
	for (int _col = 0; _col < size; ++_col)
	{
		for (int _row = 0; _row < size; ++_row)
		{
			if (maze[_col][_row]) maze[_col][_row]->render(_window);
		}
	}
}

int Maze::getSize()
{
	return size;
}

int Maze::getBoxSize()
{
	return boxSize;
}

void Maze::reload(int _size, int _windowWidth)
{

}