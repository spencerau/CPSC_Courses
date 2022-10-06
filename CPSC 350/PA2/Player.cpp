/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA2

CPP File for Player. Implements both a default constructor and one that takes initial lives as a parameter. Sets
all variables to 0 and alive to true with the exception of setting lives to 0 if default or to the parameter
*/

#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player(int lives) {
    this->lives = lives;
    coins = 0;
    PL = 0;
    row = 0;
    col = 0;
    streak = 0;
    stage = 0;
    alive = true;
}

Player::Player() {
    this->lives = 1;
    coins = 0;
    PL = 0;
    row = 0;
    col = 0;
    streak = 0;
    stage = 0;
    alive = true;
}

Player::~Player() {

}