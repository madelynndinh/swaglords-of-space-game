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

//Players
Player* player;
int points;

//Enemies
Enemy* enemy;


sf::Font font;
sf::Text guiText;
sf::Text endGameText;


    //Private functions

void initWindow();
void initVariables();
void initFont();
void initText();
void initTextures();
void initPlayer();



public:
    Game(/* args */);
    ~Game();


//Accessors
const bool& getEndGame() const;

    //Functions
     void run();
    void updatePollEvents();

    void updateInput();
    void updateGui();
    void updateBullet();
    void update();
    void renderGui(sf::RenderTarget* target);

    void render();
};


#endif