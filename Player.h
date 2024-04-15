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

    //Private functions
    void initTexture();
    void initSprite();


public:
    Player(/* args */);
    ~Player();


    //Functions
void update();
void render(sf::RenderTarget& target);
};




#endif