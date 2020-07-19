#include "GUI.h"

GUI::GUI(Window* _window, int _width, int _height) : window(_window), gui(window->getWindow()), width(_width), height(_height)
{
	init();
}

GUI::~GUI()
{
}

void GUI::handleEvent(sf::Event& _event)
{
	//std::cout << _event.type << std::endl;
	gui.handleEvent(_event);
}

void GUI::render()
{
	gui.draw();
	//std::cout << "GUI Drawn." << std::endl;
}

void GUI::init()
{
	panel = tgui::Panel::create({ width, height });
	panel->setPosition(window->getWidth() - width, 0);
	gui.add(panel);

	lboGeneration = tgui::ListBox::create();
	lboGeneration->addItem(RECURSIVE_BACKTRACKING);
	lboGeneration->addItem(ELLER);
	lboGeneration->addItem(KRUSKAL);
	lboGeneration->addItem(PRIM);
	lboGeneration->addItem(RECURSIVE_DIVISION);
	lboGeneration->addItem(ALDOUS_BRODER);
	lboGeneration->addItem(WILSON);
	lboGeneration->addItem(HUNT_AND_KILL);
	lboGeneration->addItem(GROWING_TREE);
	lboGeneration->addItem(BINARY_TREE);
	lboGeneration->addItem(SIDEWINDER);
	lboGeneration->setPosition(5, 5);
	lboGeneration->setSelectedItemByIndex(0);
	panel->add(lboGeneration, "lboGeneration");

	lboSolution = tgui::ListBox::create();
	lboSolution->addItem(A_STAR);
	lboSolution->addItem(DIJKSTRA);
	lboSolution->addItem(D_STAR);
	lboSolution->setPosition(5, lboGeneration->getPosition().y + lboGeneration->getSize().y + 5);
	lboSolution->setSelectedItemByIndex(0);
	panel->add(lboSolution, "lboSolution");

	btnStart = tgui::Button::create("Start");
	btnStart->setPosition(5, lboSolution->getPosition().y + lboSolution->getSize().y + 5);
	panel->add(btnStart, "btnStart");

	btnPause = tgui::Button::create("Pause");
	btnPause->setPosition(btnStart->getPosition().x + btnStart->getSize().x + 5, btnStart->getPosition().y);
	panel->add(btnPause, "btnPause");
	
	btnResume = tgui::Button::create("Resume");
	btnResume->setPosition(btnPause->getPosition().x + btnPause->getSize().x + 5, btnStart->getPosition().y);
	panel->add(btnResume, "btnResume");

	btnStep = tgui::Button::create("Step");
	btnStep->setPosition(btnStart->getPosition().x, btnStart->getPosition().y + btnStart->getSize().y + 5);
	panel->add(btnStep, "btnStep");
}

tgui::Widget::Ptr GUI::getWidgetByName(std::string _name)
{
	std::vector<tgui::Widget::Ptr> _widgets = panel->getWidgets();
	tgui::Widget::Ptr _widget;

	for (auto _it = _widgets.begin(); _it != _widgets.end(); ++_it)
	{
		_widget = *_it;

		//std::cout << std::string(_widget->getWidgetName()) << " : " << _name << std::endl;

		if (std::string(_widget->getWidgetName()) == _name) return _widget;
	}

	return NULL;
}