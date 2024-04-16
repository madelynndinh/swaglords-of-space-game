#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>


class Enemy
{
private:
    sf::CircleShape shape;
    int type;
    int hp;
    int hpMax;
    int damage;
    int points;

void initShape();
void initVariables();


public:
    Enemy(float pos_x, float pos_y);
    ~Enemy();


    void update();
    void render(sf::RenderTarget* target);
};


#endif