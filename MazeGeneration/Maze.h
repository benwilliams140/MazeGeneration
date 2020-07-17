#ifndef MAZE_H
#define MAZE_H

#include <iostream>

#include "Window.h"
#include "Box.h"
#include "Array2D.h"

class Maze
{
public:
	Maze();
	~Maze();

	void update();
	void render(Window*);

	int getSize();
	int getBoxSize();

	void reload(int, int);

private:
	int size = 32;
	int boxSize = 25;

	Array2D<Box*> maze = Array2D<Box*>(size, size);
};

#endif