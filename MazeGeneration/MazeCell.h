#ifndef MAZE_CELL_H
#define MAZE_CELL_H

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Window.h"
#include "MazeWall.h"

class MazeCell
{
public:
	MazeCell(int, int, int);
	~MazeCell();

	void update();
	void render(Window*);

	int getCol();
	int getRow();

	void setColor(sf::Color);

private:
	sf::RectangleShape rect;
	MazeWall* walls[4];

	int col, row;
	bool visited;
};

#endif