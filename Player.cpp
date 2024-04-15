#include "Player.h"
#include <iostream>
#include "Game.h"

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

//Functions

void Player::move(const float dirX, const float dirY) {
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed*dirY);
}

void Player::update(){

};

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);

};