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
unsigned pointCount;
    sf::CircleShape shape;
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;//got from killing enemy

void initShape();
void initVariables();


public:
    Enemy(float pos_x, float pos_y);
    ~Enemy();

//Accessors
const sf::FloatRect getBounds() const;
const int& getPoints() const;

    void update();
    void render(sf::RenderTarget* target);
};


#endif