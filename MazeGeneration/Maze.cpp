#include "Maze.h"

Maze::Maze() : generating(false)
{
	for (int _col = 0; _col < size; ++_col)
	{
		for (int _row = 0; _row < size; ++_row)
		{
			maze[_col][_row] = new MazeCell(cellSize, _col, _row);
		}
	}

	algorithm = new Algorithm();
}

Maze::~Maze()
{

}

void Maze::update()
{
	if (generating) generating = algorithm->update(maze);
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

void Maze::generate()
{
	//std::cout << "Generating" << std::endl;
	generating = true;
}

int Maze::getSize()
{
	return size;
}

int Maze::getCellSize()
{
	return cellSize;
}

void Maze::reload(int _size, int _windowWidth)
{

}