#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>

#include "Window.h"

class Line
{
public:
	Line(int, int, int, int);
	~Line();

	void render(Window*);

private:
	sf::RectangleShape line;
};

#endif