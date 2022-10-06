/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA2

Header File for the Player Class representing Mario.

Has a constructor that takes initial lives as input and contains the variables detailing the current:
lives, coins, playerLevel, position (row and column), streak, stage, and whether the player is still alive

*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Player.h"
#include <string>

using namespace std;

class Player {
public:
    Player();
    Player(int lives);
    ~Player();
    int lives;
    int coins;
    int PL;
    int row;
    int col;
    int streak;
    int stage;
    bool alive;
private:

};

#endif