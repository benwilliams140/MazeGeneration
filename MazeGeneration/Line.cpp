#include "Line.h"

Line::Line(int _x1, int _y1, int _x2, int _y2)
{
	line.setSize(sf::Vector2f(_x2 - _x1 + 1, _y2 - _y1 + 1));
	line.setOrigin(0, 0);
	line.setPosition(sf::Vector2f(_x1, _y1));
}

Line::~Line()
{

}

void Line::render(Window* _window)
{
	_window->render(line);
}