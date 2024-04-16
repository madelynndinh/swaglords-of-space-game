#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Game.h"
#include <time.h>
using namespace sf;

int main() {
    //Seed randomization
    srand(time(static_cast<unsigned>(0)));

    Game game;

game.run();

    return 0;
}