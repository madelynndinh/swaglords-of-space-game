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
#include "Player.h"


class Game
{
private:
  
sf::VideoMode videoMode;
sf::RenderWindow* window;
bool endGame;
sf::Event sfmlEvent;

//Players
Player* player;
int points;

sf::Font font;
sf::Text guiText;
sf::Text endGameText;


    //Private functions

void initWindow();
void initVariables();
void initFont();
void initText();
void initPlayer();



public:
    Game(/* args */);
    ~Game();


//Accessors
const bool& getEndGame() const;

    //Functions
     void run();
      void pollEvents();
          void updateGui();
    void update();
    void renderGui(sf::RenderTarget* target);

    void render();
};


#endif