#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>

#include "Window.h"
#include "MazeCell.h"
#include "Array2D.h"

#include "Algorithm.h"
#include "RecursiveBacktracking.h"

#include "Common.h"

class Maze
{
public:
	Maze();
	~Maze();

	void update();
	void render(Window*);
	void reload(int, int);
	void generate();

	void pause();
	void resume();
	void step();

	int getSize();
	int getCellSize();

	void setGenerationAlgorithm(std::string);
	void setSolutionAlgorithm(std::string);

private:
	int size = 32;
	int cellSize = 25;

	Array2D<MazeCell*> maze = Array2D<MazeCell*>(size, size);
	MazeCell* startingCell;

	bool generating, solving;
	Algorithm* generation;
	Algorithm* solution;
	std::string genAlgorithm, solAlgorithm;
};

#endif