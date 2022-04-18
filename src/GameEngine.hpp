#pragma once

#include "DragonPlayer.hpp"
//While not a true engine, serves as a wrapper for the entire game
class GameEngine
{
	private:
		//Pointer for Main window object for the game
		sf::RenderWindow* mainWindow;

		//variable for window events
		sf::Event ev;
		//Create an instance of the controllable character
		DragonPlayer player;


		//Initalization of Game functions
		//Sets the Main window settings and set the mainWindow pointer to the
		//   window instance
		void initWindow();
		//Creates the main background
		void renderBackground();
	public:
		//Constructors
		GameEngine();
		~GameEngine();

		//Tell whether the game is still running or not
		bool running() const;
		//Called to update visuals of game objects
		void render();
		//Updates the game logic and positions for objects to be rendered.
		void update();
};