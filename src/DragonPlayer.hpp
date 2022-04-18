#pragma once

class DragonPlayer
{
	private:
		sf::Sprite base;
		sf::Texture skin;


	public:
		DragonPlayer();
		~DragonPlayer();

		void render(sf::RenderTarget* window);
};