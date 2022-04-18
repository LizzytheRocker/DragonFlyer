#pragma once
//Class to wrap all main aspects of the playable character
class DragonPlayer
{
	private:
		//create enity to display the playable character
		sf::Sprite base;
		//Visual for the playable character storage
		sf::Texture skin;
		//Used to change movement speed
		//To be adjusted later as the game goes on
		float movementspeed;

		//Takes keyboard inputs (AWSD) and updates the location of the playable character
		void updatePosition();
		//Checks to make sure the playable character has not left the screen
		void updateBoundsCollisons(const sf::RenderTarget* window);
	public:
		//Constructors
		DragonPlayer();
		~DragonPlayer();
		//Renders the visuals of the playable character
		void render(sf::RenderTarget* window);
		//updates logic and position for the playable character
		void update(const sf::RenderTarget* window);
};