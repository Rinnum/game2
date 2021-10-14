#include "Game.h"
#include "Player.h"

//Private function
void Game::initVariables()
{
	this->window = nullptr;
    //Game ligic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    this->points = 0;
    this->enemySpawnTimer = 100.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->mouseHeld = false;
}

void Game::initWindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new RenderWindow(this->videoMode,"Don't Touch My Town",Style::Titlebar | Style::Close);
    this->bgTexture.loadFromFile("character/bg.png");
    this->bgSprite.setTexture(bgTexture);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(true);
}

void Game::initPlayer()
{
    this->player = new Player();
    /*this->playerTexture.loadFromFile("character/player1.png");
    this->playerSprite.setTexture(playerTexture);
    this->playerSprite.setPosition(900.f, 560.f);
    this->playerSprite.setScale(0.1f, 0.1f);*/
}

void Game::initBullet()
{
    this->bullet = new Bullet();
}

void Game::initEnemies()
{
   //this->enemy.setPosition(10.f, 10.f);
    
    this->enemyTexture.loadFromFile("character/enemy1.png");
    this->enemySprite.setTexture(enemyTexture);
    this->enemy.setSize(Vector2f(100.0f, 100.0f));
}
//Constructors / Destructors
Game::Game()
{
this->initVariables();
this->initWindow();
this->initBullet();
this->initEnemies();
this->initPlayer();

}

Game::~Game()
{
    delete this->window;
    delete this->player;

    //Delete texture
    for (auto& i : this->bullet);
    {
        delete i.second;
    }
}

//Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}


//Function
void Game::spawnEnemy()
{
    /*
        return void
        Spwan enemies and set colors and position
        -Sets a random position
        -Set a random color
        -Adds enemy to the vector
    */
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),10 );

    this->enemy.setTexture(&enemyTexture);

    //Spawn the enemy
    this->enemies.push_back(this->enemy);
}

void Game::pollEvents()
{
    //Event polling
    while (this->window->pollEvent(this->ev))
    {
        if (ev.Event::type == Event::Closed)
            this->window->close();
        if (ev.Event::KeyPressed && ev.Event::key.code == Keyboard::Escape)
            this->window->close();
    }
}


void Game::updateMousePosition()
{
    /*
       @return void

        -update mouseposition
    */
    this->mousePosWindow = ::Mouse::getPosition(*this->window);
    this->mousePosview = this->window->mapPixelToCoords(this->mousePosWindow);
}


void Game::updateEnemies()
{
    /*
        @return void
        Upadate the enemy spawn timer and spawn enemies
        -Move the enemy downwards.
        -Remove the enemies at the edge of the screen //TODO
    */

    //Updating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    //Moving and updateing enemies 
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        this->enemies[i].move(0.f, 1.f);

        if (this->enemies[i].getPosition().y > this->window->getSize().y)
            this->enemies.erase(this->enemies.begin() + i);
    }
    //Check if click upon
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        if (this->mouseHeld == false)
        {
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
            {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosview))
                {
                    //Delete enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                    //Gain points
                    this->points += 1.f;
                }
            }
        }
        else
        {
            this->mouseHeld = false;
        }
    }
}

void Game::updateBullet()
{

}

/*void Game::updatePlayers(float deltaTime)
{
    //Game player
        //Move Player
    if (Keyboard::isKeyPressed(Keyboard::Key::A))
    {
        this->player->move(-500.0f*deltaTime, 0.0f);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        this->player->move(500.0f*deltaTime, 0.0f);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::W))
    {
        this->player->move(0.0f, -500.0f*deltaTime);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::S))
    {
        this->player->move(0.0f, 500.0f*deltaTime);
    }
}*/

void Game::update(float deltaTime)
{
    this->pollEvents();
    this->updateMousePosition();
    this->updateEnemies();
    this->player->update(deltaTime);

    //->player->updateWindowBoundsCollision();
    //this->updatePlayers(deltaTime);
    cout << deltaTime << endl;
}
    

void Game::renderEnemies()
{
    //Rendering all the enemies
    for (auto& e : this->enemies)
    {
        this->window->draw(e);
    }
}


void Game::render()
{
    /*
       @return void

        -clear old frame
        -Render new object
        -display frame in Wiondow
        Render the game objects.    
    */
   
    this->window->clear();

    //Draw Game Objects
    this->window->draw(this->bgSprite);
    //this->window->draw(this->playerSprite);
    this->player->render(this->window);
    this->renderEnemies();
    this->window->display();
}

