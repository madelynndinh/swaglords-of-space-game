#include "Game.h"
#include "Player.h"

#include <iostream>

void Game::initVariables() { 
  this->endGame = false;
  this-> points =0;
  }

void Game::initWindow() {
  this->videoMode = sf::VideoMode(800, 600);
  this->window= new sf::RenderWindow(this->videoMode, "Swaglords of Space - Game 3",
                                       sf::Style::Close | sf::Style::Titlebar);
  this->window->setFramerateLimit(60)  ;   

  //limit the number of frames displayed to the refresh rate of the monitor
  this->window->setVerticalSyncEnabled(false)  ;                               
}


void Game::initFont()
{
if(this->font.loadFromFile("/Users/minhtamdinh/Documents/OOP/project/demo/pick-up-swag-balls-game/Bungee_Spice/BungeeSpice-Regular.ttf"))
{
  std::cout << "ERROR::GAME::INITFONTS::"<<std::endl;
};

};


void Game::initText()
{
  //init guitext
this->guiText.setFont(this->font);
this->guiText.setFillColor(sf::Color::White);
this->guiText.setCharacterSize(32);


//End game text
this->endGameText.setFont(this->font);
this->endGameText.setFillColor(sf::Color::Red);
this->endGameText.setCharacterSize(60);
this->endGameText.setPosition(sf::Vector2f(20,300));
this->endGameText.setString("YOU ARE DEAD!");
};

// Constructors and Destructors2
Game::Game() {
  this->initVariables();
  this->initWindow();
  this->initFont();
  this->initText();
};

Game::~Game() { delete window; };

//Accessors
const bool& Game::getEndGame() const
{
return false;
};


  void Game::run()
  {

    while (this->window->isOpen())
    {
      this->update();
 this->render();
    }
    

  };


  void Game::pollEvents() {
  // Event polling
  while (this->window->pollEvent(this->sfmlEvent)) {
    switch (this->sfmlEvent.type) {
      case sf::Event::Closed:
        this->window->close();
        break;

      case sf::Event::KeyPressed:
        if (this->sfmlEvent.key.code == sf::Keyboard::Escape) {
          this->window->close();
          break;
        };
    }
  }
  }

  void Game::update() 
{ 
  this->pollEvents(); 

  if (this->endGame == false)
  {

  this->updateGui();

  }
}

  void Game::render() {
  this->window->clear();

  // Render stuff
 


//RENDER GUI
this->renderGui(this->window);

//Render end text
if (this->endGame == true)
{
  this->window->draw(this->endGameText);
}

  this->window->display();
};
