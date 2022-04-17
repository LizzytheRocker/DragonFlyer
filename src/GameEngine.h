#pragma once

class GameEngine
{
	private:
		sf::VideoMode videoMode;
		sf::RenderWindow* mainWindow;
	public:
		GameEngine();
		~GameEngine();
};