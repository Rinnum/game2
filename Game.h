#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include"Player.h"
#include"Bullet.h"
#include<map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;
/*
	Class that acts the game engine
*/

class Game
{
private:
	//Variable
	
	//Window
	//vector<Background> backgrounds;
	RenderWindow* window;
	VideoMode videoMode;
	RectangleShape bg;
	Texture bgTexture;
	Sprite bgSprite;
	Event ev;

	//Bullet
	Bullet* bullet;

	//Mouse positions
	Vector2i mousePosWindow;
	Vector2f mousePosview;

	//Game logic
	unsigned points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;
	
	//Game objects
	//enemy
	vector<RectangleShape> enemies;
	RectangleShape enemy;
	Texture enemyTexture;
	Sprite enemySprite;

	//Player
	Player* player;
	//Texture playerTexture;
	//Sprite playerSprite;

	//Private function
	void initVariables();
	void initWindow();
	void initPlayer();
	void initBullet();
	void initEnemies();

public:
	//Constructor/Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;


	//Function 
	void spawnEnemy();
	void pollEvents();
	void updateMousePosition();
	//void updatePlayers(float deltaTime);
	void updateEnemies();
	void updateBullet();
	void update(float deltaTime);
	void renderEnemies();
	void render();
};

