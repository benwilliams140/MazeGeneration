#ifndef MAZE_WALL_H
#define MAZE_WALL_H

#include <SFML/Graphics.hpp>

#include "Window.h"

class MazeWall
{
public:
	MazeWall(int, int, int, int);
	~MazeWall();

	void render(Window*);

	bool shouldRender();

private:
	sf::RectangleShape line;
	bool visible;
};

#endif