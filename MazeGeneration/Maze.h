#ifndef MAZE_H
#define MAZE_H

#include <iostream>

#include "Window.h"
#include "MazeCell.h"
#include "Array2D.h"
#include "Algorithm.h"

class Maze
{
public:
	Maze();
	~Maze();

	void update();
	void render(Window*);
	void reload(int, int);
	void generate();

	int getSize();
	int getCellSize();

private:
	int size = 32;
	int cellSize = 25;

	bool generating;

	Array2D<MazeCell*> maze = Array2D<MazeCell*>(size, size);
	Algorithm* algorithm;
};

#endif