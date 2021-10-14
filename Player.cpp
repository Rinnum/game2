#include "Player.h"


void Player::initplayerTexture()
{
	//Load a Texture from file
	this->playerTexture.loadFromFile("character/player1.png");
}

void Player::initplayerSprite()
{
	//Set texture sprit
	this->playerSprite.setTexture(this->playerTexture);
	//Resize the sprite
	this->playerSprite.setScale(10.f,10.f);
	this->playerSprite.setTexture(playerTexture);
	this->playerSprite.setPosition(900.f, 560.f);
	//this->playerSprite.setScale(0.1f, 0.1f); 
}

Player::Player()
{
    this->movementSpeed = 1000.f;

	this->initplayerTexture();
	this->initplayerSprite();
}

Player::~Player()
{

}


void Player::updatePlayers(float deltaTime)
{
	//Game player
	velocity.y = 0.f;
	velocity.x = 0.f;

		//Move Player
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		velocity.x += -movementSpeed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		velocity.x += movementSpeed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
	{
		velocity.y += -movementSpeed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		velocity.y += movementSpeed * deltaTime;
	}

	this->playerSprite.move(velocity);
}

void Player::updateWindowBoundsCollision()
{
	//Left
	if (this->playerSprite.getPosition().x < 0.f)
	{
		this->playerSprite.setPosition(0.f, playerSprite.getPosition().y);
	}
	//Top
	if (this->playerSprite.getPosition().y < 0.f)
	{
		this->playerSprite.setPosition(playerSprite.getPosition().x, 0.f);
	}
	//Right
	if (this->playerSprite.getPosition().x + playerSprite.getGlobalBounds().width > 1920)
	{
		this->playerSprite.setPosition(1920 - playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
	}
	//Bottom
	if (this->playerSprite.getPosition().y + playerSprite.getGlobalBounds().height > 1080)
	{
		this->playerSprite.setPosition(playerSprite.getPosition().x, 1080 - playerSprite.getGlobalBounds().height);
	}
}

void Player::move(const float dirX, const float dirY)
{
	this->playerSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

//Function
void Player::update(float deltaTime)
{
	//Window bounds collision
	this->updateWindowBoundsCollision();

	this->updatePlayers(deltaTime);
	
}

void Player::render(RenderTarget* target)
{
	target->draw(this->playerSprite);
}
