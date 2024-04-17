#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;
    float attackCoolDown;
    float attackCoolDownMax;

    int hp;
    int hpMax;

    //Private functions
    void initVariables();
    void initTexture();
    void initSprite();
  

public:
    Player(/* args */);
    ~Player();

//Accessor
const sf::Vector2f& getPos() const;
const sf::FloatRect getBounds() const;
const int& getHp() const;
const int& getHpMax() const;

//Modifiers
void setPosition(const sf::Vector2f pos );
void setPosition(const float x, const float y);
void setHp(const int hp);
void loseHp(const int value );

    //Functions

    void move(const float dirX, const float dirY);
const bool canAttack();

    void updateAttack();
void update();
void render(sf::RenderTarget& target);
};




#endif