#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player
{
private:

	Sprite playerSprite;
	Texture playerTexture;
	Vector2f velocity;

	float movementSpeed;

	//Private function
	void initplayerTexture();
	void initplayerSprite();

public:

	Player();
	virtual ~Player();

	//Function
	void updatePlayers(float deltaTime);
	void updateWindowBoundsCollision();
	void move(const float dirX, const float dirY);
	void update(float deltaTime);
	void render(RenderTarget* target);
};

