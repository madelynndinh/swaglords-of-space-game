#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
  
sf::VideoMode videoMode;
sf::RenderWindow* window;
bool endGame;
sf::Event sfmlEvent;

//Resources
//Mapping key - values
std::map <std::string, sf::Texture*> textures;
std::vector<Bullet*> bullets;

//GUI
sf::Font font;
sf::Text pointText;
sf::Text endGameText;

//World
sf::Texture worldBackgroundText;
sf::Sprite worldBackGround;

//System
unsigned points;

//Players
Player* player;

//Player GUI
sf::RectangleShape playerHpBar;
sf::RectangleShape playerHpBarBack;

//Enemies
float spawnTimer;
float spawnTimerMax;

std::vector <Enemy*> enemies;



    //Private functions

void initWindow();
void initVariables();
void initGUI();
void initTextures();
void initWorld();
void initSystem();
void initPlayer();
void initEnemies();


public:
    Game(/* args */);
    ~Game();


//Accessors
const bool& getEndGame() const;



    //Functions
    void run();
    void updatePollEvents();
    void updateGui();
    void updateWorld();
    void updateInput();
    void updateCollision();
    void updateBullet();
    void updateEnemies();
    void updateCombat();
    void update();


    void renderGui(sf::RenderTarget* target);
void renderWorld();
    void render();
};


#endif