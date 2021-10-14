#include "Bullet.h"

void Bullet::initbulletTexture()
{
	this->bulletTexture.loadFromFile("character/bullet.png");
}

void Bullet::initbulletSprite()
{
	//Set texture sprit
	this->bulletSprite.setTexture(this->bulletTexture);
	//Resize the sprite
	this->bulletSprite.setScale(5.f, 5.f);
	this->bulletSprite.setTexture(bulletTexture);
}

Bullet::Bullet()
{
	this->initbulletTexture();
	this->initbulletSprite();
}


Bullet::~Bullet()
{

}



void Bullet::updateBullet()
{
	//Movement
	/*this->movementSpeed = movement_speed;
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	*/
	this->bulletSprite.move(this->movementSpeed * this->direction);
}

void Bullet::update()
{

}

void Bullet::render(RenderTarget* target)
{
	target->draw(this->bulletSprite);
}
