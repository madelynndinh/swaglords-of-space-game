#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include <iostream>


Bullet::Bullet(/* args */)
{
}


Bullet::Bullet(sf::Texture& texture, float dirX, float dirY, float movement_speed)
{

    this->shape.setTexture(texture);
    this->direction.x = dirX;
    this->direction.y = dirY;
    this->movementSpeed = movement_speed;


}

Bullet::~Bullet()
{
}




    void Bullet::update()
    {
this->shape.move(this->movementSpeed * this->direction);
    };



    void Bullet::render(sf::RenderTarget* target)
    {
target->draw(this->shape);
    };