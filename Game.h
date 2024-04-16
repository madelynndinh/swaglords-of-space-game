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


//Players
Player* player;
int points;

//Enemies
float spawnTimer;
float spawnTimerMax;

std::vector <Enemy*> enemies;



    //Private functions

void initWindow();
void initVariables();
void initFont();
void initText();
void initTextures();
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
    void updateInput();
   
    void updateBullet();
    void updateEnemiesAndCombat();
    void update();
    void renderGui(sf::RenderTarget* target);

    void render();
};


#endif