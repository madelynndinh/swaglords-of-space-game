#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

void Game::initVariables() { 
  this->endGame = false;
 
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
if(!this->font.loadFromFile("/Users/minhtamdinh/Documents/OOP/project/demo/swaglords-of-space-game/Fonts/PixellettersFull.ttf"))
{
  std::cout << "ERROR::GAME::INITFONTS::"<<std::endl;
};

};


void Game::initText()
{
  //init pointtext
this->pointText.setFont(this->font);
this->pointText.setFillColor(sf::Color::White);
this->pointText.setCharacterSize(12);
this->pointText.setString("Points: ");

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

void Game::initWorld()
{
  if(!this->worldBackgroundText.loadFromFile("/Users/minhtamdinh/Documents/OOP/project/demo/swaglords-of-space-game/Textures/background1.jpg"))
  {
std::cout<<"ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE"<<"\n";
  }
    this->worldBackGround.setTexture(this->worldBackgroundText);

};

void Game::initSystem(){
 this-> points =0;
};

void Game::initPlayer(){
this->player = new Player();
};

void  Game::initEnemies()
{
this->spawnTimerMax = 50.f;
this->spawnTimer = this->spawnTimerMax;
}


// Constructors and Destructors2
Game::Game() {
  this->initVariables();
  this->initWindow();
  this->initFont();
  this->initText();
  this->initTextures();
  this->initWorld();
  this->initPlayer();
  this->initEnemies();
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
    
    //Delete enemies
    for (auto *i: this->enemies)
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
   void Game::updateGui()
   {
    std::stringstream ss;
    ss<<"Points: "<<this->points;
this->pointText.setString(ss.str());
   };

void Game::updateWorld(){
this->points = 0;
};

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
    this->bullets.push_back(
      new Bullet(
        this->textures["BULLET"],
        this->player->getPos().x + this->player->getBounds().width/2.f,
        this->player->getPos().y,
        0.f,-1.f,10.f));
  }
  
  };

  void Game::updateCollision()
  {
    //Left World collision
if(this->player->getBounds().left <0.f)
{
this->player->setPosition(0.f,this->player->getBounds().top);
}

//Right World collision
else if(this->player->getBounds().left+this->player->getBounds().width>=this->window->getSize().x)
{
this->player->setPosition(this->window->getSize().x-this->player->getBounds().width,this->player->getBounds().top);
}


//Top World collision
if(this->player->getBounds().top <0.f)
{
this->player->setPosition(this->player->getBounds().left,0.f);
}

//Bottom World collision
else if(this->player->getBounds().top+this->player->getBounds().height>=this->window->getSize().y)
{
this->player->setPosition(this->player->getBounds().left,this->window->getSize().y-this->player->getBounds().height);
}
  }

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

void Game::updateEnemies()
{
  //Spawning
  this->spawnTimer += 0.5f;
if (this->spawnTimer >= this->spawnTimerMax)
{
  this->enemies.push_back(new Enemy(rand()%this->window->getSize().x-20.f, -100.f));
  this->spawnTimer = 0.f;
}


//Update
    unsigned counter = 0;

for(auto *enemy: this->enemies)
{
    enemy->update();
    if (enemy->getBounds().top > this->window->getSize().y)
    {
        //Delete enemy
        delete this->enemies.at(counter);
       this->enemies.erase(this->enemies.begin()+counter);
       --counter;
    }
    counter +=1;
}
};


void Game:: updateCombat(){
for(int i = 0; i<this->enemies.size();i++)
{
  bool enemy_removed = false;
  this->enemies[i]->update();
    for (size_t k = 0; k < this->bullets.size()&&!enemy_removed; k++)
    {
      if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())&& !enemy_removed)
      {
        delete bullets[k];
        delete enemies[i];
        this->bullets.erase(this->bullets.begin()+k);
        this->enemies.erase(this->enemies.begin()+i);

      enemy_removed=true;
      }
    }
}

};


  void Game::update() 
{ 
  this->updatePollEvents(); 
this->updateInput();
this->player->update();
this->updateCollision();
this->updateWorld();
this->updateEnemies();
this->updateCombat();
this->updateBullet();


//   if (this->endGame == false)
//   {

   this->updateGui();

//   }
}

 void Game::renderGui(sf::RenderTarget* target)
 {
this->window->draw(this->pointText);
 };


void Game::renderWorld()
{
  this->window->draw(this->worldBackGround);
}

  void Game::render() {
  this->window->clear();

//Draw the world;
this->renderWorld();

  // Render stuff
 
this->player->render(*this->window);

for(auto *bullet: this->bullets)
{
    bullet->render(this->window);
}

for(auto *enemy: this->enemies)
{
    enemy->render(this->window);
}

 //RENDER GUI
this->renderGui(this->window);

//Render end text
if (this->endGame == true)
{
  this->window->draw(this->endGameText);
}

  this->window->display();
};
