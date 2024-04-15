#include "Game.h"
#include "Player.h"
#include "Bullet.h"
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
void Game::initTextures(){

this->textures["BULLET"] = new sf::Texture;
this->textures["BULLET"] ->loadFromFile("/Users/minhtamdinh/Documents/OOP/project/demo/swaglords-of-space-game/Textures/bullet.png");
};


void Game::initPlayer(){
this->player = new Player();
};


// Constructors and Destructors2
Game::Game() {
  this->initVariables();
  this->initWindow();
  this->initFont();
  this->initText();
  this->initTextures();
  this->initPlayer();
}


Game::~Game() { 
    
    delete window; 
    delete player;
    
    //delete Textures
    for (auto &i : this ->textures)
    {
        delete i.second;
    }
    

    //delete remaining bullets
    for (auto *i: this->bullets)
    {
        delete i;  
    }
    
    };

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


  void Game::updatePollEvents() {
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


  void Game::updateInput()
  {
  //Move player
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->player->move(-1.f, 0.f);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->player->move(1.f, 0.f);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->player->move(0.f, -1.f);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    this->player->move(0.f, 1.f);
  }


  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&this->player->canAttack())
  {
    this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPos().x,this->player->getPos().y,0.f,-1.f,10.f));
  }
  
  };
void Game::updateBullet(){
    unsigned counter = 0;
for(auto *bullet: this->bullets)
{
    //bullet culling (top of screen)
    bullet->update();
    if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
    {
        //Delete bullet go outside of the screen
        delete this->bullets.at(counter); //delete pointer to that bullet
       this->bullets.erase(this->bullets.begin()+counter);
       --counter;
    }
    counter +=1;
}
};
  void Game::update() 
{ 
  this->updatePollEvents(); 
this->updateInput();
this->player->update();
this->updateBullet();


//   if (this->endGame == false)
//   {

//   this->updateGui();

//   }
}

  void Game::render() {
  this->window->clear();

  // Render stuff
 
this->player->render(*this->window);

for(auto *bullet: this->bullets)
{
    bullet->render(this->window);
}
// //RENDER GUI
// this->renderGui(this->window);

//Render end text
if (this->endGame == true)
{
  this->window->draw(this->endGameText);
}

  this->window->display();
};
