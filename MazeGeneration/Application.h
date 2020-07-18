#ifndef APPLICATION_H
#define APPLICATION_H

#include <thread>

#include "Window.h"
#include "Maze.h"
#include "GUI.h"

const std::string WINDOW_TITLE = "Maze Generation";
const unsigned int GUI_WIDTH = 200;

class Application
{
public:
	Application();
	~Application();

	void start();

private:
	void loop();
	void getInput();
	void update(float);
	void render();

	void initGUI();

	Window* window;
	Maze* maze;
	GUI* gui;

	float timeSinceLastUpdate;
	float timeBetweenUpdates;
};

#endif