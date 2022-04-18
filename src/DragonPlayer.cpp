#include "DragonPlayer.hpp"

DragonPlayer::DragonPlayer()
{
	if (!this->skin.loadFromFile("content/DragonSprite.png"))
	{
		//error
	}
	this->base.setTexture(skin);
}

DragonPlayer::~DragonPlayer(){
	//need to determine what needs to be destroyed
}

void DragonPlayer::render(sf::RenderTarget* window){
	window->draw(this->base);
}