#include "Player.h"
#include <iostream>
#include "Game.h"

  void Player::initTexture()
  {
    //Load texture from file



  };


    void Player::initSprite()
    {
//Set the texture to the sprite
this->sprite.setTexture(this->texture);


    };



Player::Player(/* args */)
{

    this->initTexture();
    this->initSprite();
}

Player::~Player()
{
}

void Player::update()
{

};


void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);

};