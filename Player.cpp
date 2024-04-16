#include "Player.h"
#include <iostream>
#include "Game.h"

 void Player::initVariables()
 {
this->movementSpeed = 2.f;

this->attackCoolDownMax = 10.f;
this->attackCoolDown = this->attackCoolDownMax ;
 };


  void Player::initTexture()
  {
    //Load texture from file
if (this->texture.loadFromFile("/Users/minhtamdinh/Documents/OOP/project/demo/swaglords-of-space-game/Textures/ship.png"))
{
    std::cout<<"ERROR::PLAYER::INITEXTURE::Could not load texture from file." << "\n";
}


  };


    void Player::initSprite()
    {
//Set the texture to the sprite
this->sprite.setTexture(this->texture);


//Resize the sprite
this->sprite.scale(0.1f,0.1f);

    };



Player::Player(/* args */)
{
    this->movementSpeed = 10.f;
    this->initVariables();
    this->initTexture();
    this->initSprite();
}

Player::~Player()
{
}


//Accessor
const sf::Vector2f& Player::getPos() const
{
    return this->sprite.getPosition();
};

const sf::FloatRect Player::getBounds() const
{
    return this->sprite.getGlobalBounds();
}
;
//Functions

void Player::move(const float dirX, const float dirY) {
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed*dirY);
}


const bool Player::canAttack()
{
if (this->attackCoolDown >= this->attackCoolDownMax)
{
    this->attackCoolDown = 0.f;
   return true;
}
return false;
};
    void Player::updateAttack()
    {
if (this->attackCoolDown<this->attackCoolDownMax)
{
    this->attackCoolDown +=0.5f;
}

    };

void Player::update(){
this->updateAttack();
};

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);

};