#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>
#include "Player.h"

class Bullet
{
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float movementSpeed;

public:
Bullet();
    Bullet(sf::Texture& texture, float dirX, float dirY, float movement_speed);
    ~Bullet();



    void update();
    void render(sf::RenderTarget* target);
};


#endif