#include "Application.h"

Application::Application() : frameCount(0)
{
	srand(time(NULL));

	maze = new Maze();
	
	int _windowWidth = maze->getSize() * maze->getCellSize() + GUI_WIDTH;
	int _windowHeight = maze->getSize() * maze->getCellSize();

	window = new Window(WINDOW_TITLE, _windowWidth, _windowHeight);
	gui = new GUI(window, GUI_WIDTH, _windowHeight);

	initGUI();
}

Application::~Application()
{

}

void Application::start()
{
	loop();
}

void Application::loop()
{
	sf::Clock _clock;
	window->setFrameLimit(60);

	while (window->isOpen())
	{
		getInput();
		update(_clock.restart().asSeconds());
		render();
	}
}

void Application::getInput()
{
	sf::Event _event;
	while (window->pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed) window->close();

		gui->handleEvent(_event);
	}
}

void Application::update(float _deltaTime)
{
	++frameCount;
	maze->update();
}

void Application::render()
{
	window->clear();

	maze->render(window);
	gui->render();

	window->display();
}

void Application::initGUI()
{
	tgui::Widget::Ptr _widget = gui->getWidgetByName("btnStart");
	if (_widget)
	{
		_widget->connect(tgui::Signals::Button::Pressed, [&]()
			{
				maze->generate();
			});
	}

	_widget = gui->getWidgetByName("lboGeneration");
	if (_widget)
	{
		_widget->connect(tgui::Signals::ListBox::ItemSelected, [&](std::string _item)
			{
				maze->setGenerationAlgorithm(_item);
			});
	}

	_widget = gui->getWidgetByName("lboSolution");
	if (_widget)
	{
		_widget->connect(tgui::Signals::ListBox::ItemSelected, [&](std::string _item)
			{
				maze->setSolutionAlgorithm(_item);
			});
	}

	_widget = gui->getWidgetByName("btnPause");
	if (_widget)
	{
		_widget->connect(tgui::Signals::Button::Pressed, [&]()
			{
				maze->pause();
			});
	}

	_widget = gui->getWidgetByName("btnResume");
	if (_widget)
	{
		_widget->connect(tgui::Signals::Button::Pressed, [&]()
			{
				maze->resume();
			});
	}

	_widget = gui->getWidgetByName("btnStep");
	if (_widget)
	{
		_widget->connect(tgui::Signals::Button::Pressed, [&]()
			{
				maze->step();
			});
	}
}