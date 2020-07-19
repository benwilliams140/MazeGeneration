#ifndef MAZE_CELL_H
#define MAZE_CELL_H

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Window.h"
#include "MazeWall.h"

const sf::Color INITIAL_COLOR = sf::Color(146, 146, 146);
const sf::Color VISITED_COLOR = sf::Color(255, 0, 255);
const sf::Color PATH_COLOR = sf::Color(0, 255, 0);

class MazeCell
{
public:
	MazeCell(int, int, int);
	~MazeCell();

	void update();
	void render(Window*);
	void removeWall(MazeCell*);

	int getCol();
	int getRow();
	bool isVisited();
	MazeWall* getWall(int);

	void setColor(sf::Color);
	void visit();

private:
	sf::RectangleShape rect;
	MazeWall* walls[4];

	int col, row;
	bool visited;
};

#endif