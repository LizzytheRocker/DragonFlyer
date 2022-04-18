#include "DragonPlayer.hpp"

DragonPlayer::DragonPlayer()
{
	if (!this->skin.loadFromFile("content/DragonSprite.png"))
	{
		//error to put here
	}
	//this code will be altered when a sprite sheet is used instead
	this->base.setTexture(skin);
	//starting position for character
	this->base.setPosition(400.f,400.f);
	//setting starting movement speed
	this->movementspeed = 0.25;
}

DragonPlayer::~DragonPlayer(){
	//need to determine what needs to be destroyed
}

void DragonPlayer::render(sf::RenderTarget* window){
	window->draw(this->base);
}

void DragonPlayer::updatePosition(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->base.move(-this->movementspeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->base.move(this->movementspeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->base.move(0.f, -this->movementspeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->base.move(0.f,this->movementspeed);
	}

}

void DragonPlayer::updateBoundsCollisons(const sf::RenderTarget * window){
	//Left
	if (this->base.getGlobalBounds().left <= 0.f)
		this->base.setPosition(0.f, this->base.getGlobalBounds().top);
	//Right
	if (this->base.getGlobalBounds().left + this->base.getGlobalBounds().width >= window->getSize().x)
		this->base.setPosition(window->getSize().x - this->base.getGlobalBounds().width, this->base.getGlobalBounds().top);
	//Top
	if (this->base.getGlobalBounds().top <= 0.f)
		this->base.setPosition(this->base.getGlobalBounds().left, 0.f);
	//Bottom
	if (this->base.getGlobalBounds().top + this->base.getGlobalBounds().height >= window->getSize().y)
		this->base.setPosition(this->base.getGlobalBounds().left, window->getSize().y - this->base.getGlobalBounds().height);
}

void DragonPlayer::update(const sf::RenderTarget* window){
	this->updatePosition();
	this->updateBoundsCollisons(window);
}