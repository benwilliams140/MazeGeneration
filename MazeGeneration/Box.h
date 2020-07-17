#ifndef BOX_H
#define BOX_H

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Window.h"
#include "Line.h"

class Box
{
public:
	Box(int, int, int);
	~Box();

	void update();
	void render(Window*);

private:
	sf::RectangleShape rect;
	Line* lines[4];

	bool visited;
};

#endif