/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA2

Header File for World Class. 

Constructor takes levels, dimensions, initial lives, coins, empty spaces, 
Goomba and Koopa enemies, mushrooms, and name of the output file as parameters

play() simulates a game

contains an array of Levels, a pointer towards a Player object, number of levels
string for the output file, and total number of moves
*/

#ifndef WORLD_H
#define WORLD_H

#include "Player.h"
#include "Level.h"
#include "World.h"
#include <string>
#include <stdlib.h>

using namespace std;

class World {
public:
    World();
    World(int levels, int N, int lives, int coins, int empty, int goomba, int koopa, int mushroom, string output);
    void play();
    Level **world;
    Player *mario;
    int levels;
    string output;
    int moves;
private:

};

#endif