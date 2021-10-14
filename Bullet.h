#pragma once
#ifndef BULLET_H
#define BULLET_H

#include<SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Bullet
{
private:
	Texture bulletTexture;
	Sprite bulletSprite;
	Vector2f direction;
	float movementSpeed;

	void initbulletTexture();
	void initbulletSprite();

public:
	Bullet();
	virtual ~Bullet();

	void updateBullet();
	void update();
	void render(RenderTarget* target);
};

#endif // !BULLET_H