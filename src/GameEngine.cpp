#include "GameEngine.hpp"

void GameEngine::initWindow(){
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	this->mainWindow = new sf::RenderWindow(sf::VideoMode(1024,780,desktop.bitsPerPixel), "Dragon Flyer",sf::Style::Close | sf::Style::Titlebar);
}

//Note: Probably will/should move shape out of this function when moving texture added to background
void GameEngine::renderBackground(){
	sf::ConvexShape ground;
	//set size and location of ground shape and place it into the main window
	ground.setPointCount(6);
	ground.setPoint(0, sf::Vector2f(0.f,150.f));
	ground.setPoint(1, sf::Vector2f(424.f,400.f));
	ground.setPoint(2, sf::Vector2f(600.f,400.f));
	ground.setPoint(3, sf::Vector2f(1024.f,150.f));
	ground.setPoint(4, sf::Vector2f(1024.f,0.f));
	ground.setPoint(5, sf::Vector2f(0.f,0.f));
	ground.setRotation(180.f);
	ground.move(1024.f,780.f);
	ground.setFillColor(sf::Color::Green);
	this->mainWindow->draw(ground);
}

GameEngine::GameEngine()
{
	this->initWindow();
}

GameEngine::~GameEngine()
{
	delete this->mainWindow;
}

bool GameEngine::running()const
{
	return this->mainWindow->isOpen();
}

void GameEngine::render()
{
		this->mainWindow->clear(sf::Color(79,202,227));
		this->renderBackground();
		this->player.render(mainWindow);
		this->mainWindow->display();
}

void GameEngine::update(){
		while (this->mainWindow->pollEvent(this->ev))
		{
			if (ev.type == sf::Event::Closed)
				this->mainWindow->close();
		}
		this->player.update(mainWindow);
}