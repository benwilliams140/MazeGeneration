#ifndef GUI_H
#define GUI_H

#include <TGUI/TGUI.hpp>
#include <iostream>

#include "Window.h"
#include "Common.h"

class GUI
{
public:
	GUI(Window*, int, int);
	~GUI();

	void handleEvent(sf::Event&);
	void render();

	tgui::Widget::Ptr getWidgetByName(std::string);

private:
	void init();

	Window* window;

	tgui::Gui gui;
	tgui::Panel::Ptr panel;
	tgui::Button::Ptr btnStart;
	tgui::Button::Ptr btnPause;
	tgui::Button::Ptr btnResume;
	tgui::ListBox::Ptr lboGeneration;
	tgui::ListBox::Ptr lboSolution;

	int width, height;
};

#endif