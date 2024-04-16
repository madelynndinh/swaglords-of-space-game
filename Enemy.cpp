
#include "Enemy.h"

#include <iostream>

void Enemy::initShape() {
  this->shape.setRadius(rand() % 20 + 20);
  this->shape.setPointCount(rand() % 20 + 3);
};

void Enemy::initVariables() {
  this->type = 0;
  this->hp = 10;
  this->hpMax = 0;
  this->damage = 1;
  this->points = 5;
};

Enemy::Enemy(float pos_x, float pos_y) {
  this->initShape();
  this->initVariables();

  this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy() {}


void Enemy::update()
{

};
    void Enemy::render(sf::RenderTarget* target)
    {
        target->draw(this->shape);
    };