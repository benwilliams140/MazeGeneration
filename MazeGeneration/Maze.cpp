#include "Maze.h"

Maze::Maze() : generating(false), solving(false), genAlgorithm(RECURSIVE_BACKTRACKING), solAlgorithm(A_STAR)
{
	for (int _col = 0; _col < size; ++_col)
	{
		for (int _row = 0; _row < size; ++_row)
		{
			maze[_col][_row] = new MazeCell(cellSize, _col, _row);
		}
	}

	startingCell = maze[0][0];

	generation = NULL;
	solution = NULL;
}

Maze::~Maze()
{

}

void Maze::update()
{
	/*
	for (int _col = 0; _col < size; ++_col)
	{
		for (int _row = 0; _row < size; ++_row)
		{
			if(generating || solving) maze[_col][_row]->update();
		}
	}
	*/

	if (generating && generation)
	{
		generating = generation->update(maze);
		if (!generating) solving = true;
	}

	if (solving && solution) solving = solution->update(maze);
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
	if (!genAlgorithm.compare(RECURSIVE_BACKTRACKING))
		generation = new RecursiveBacktracking(startingCell);
	
	//std::cout << "Generation using " << genAlgorithm << "\nSolution using " << solAlgorithm << std::endl << std::endl;
	generating = true;
}

void Maze::pause()
{
	generating = false;
	solving = false;
}

void Maze::resume()
{
	generating = true;
	solving = true;
}

void Maze::step()
{
	if (!generating && generation) generation->update(maze);
	if (!solving && solution) solution->update(maze);
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

void Maze::setGenerationAlgorithm(std::string _genAlgorithm)
{
	genAlgorithm = _genAlgorithm;
}

void Maze::setSolutionAlgorithm(std::string _solAlgorithm)
{
	solAlgorithm = _solAlgorithm;
}