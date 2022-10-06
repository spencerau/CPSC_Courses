/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA2

Header File for Level Class

Constructor - Constructor that sets Mario to the input player pointer, N to N (dimensions), moves to 0, cont to true, and calls
populate(parameters) with the input parameters to populate the char array
populate() - populates the char array
writeToFile() - write the results of each move to the output file
environment() - handles the action of Mario interacting with an environment object (coin, mushroom, etc)
enemy() - handles the logic of Mario interacting with an enemy 
update() - updates the coordinates after a move
streak() - updates Mario's streak after a move
lose() - handles the conditions if Mario loses to an enemy
move() - handles how Mario moves and includes wrapping around so if Mario moves right and he's at the very right, 
then he wraps around to the left for example
print() - prints the contents of the char array onto the output file

Has variables:
char **level that represents a level populated with various objects
int N - dimensions
bool cont - whether the game will continue or not on the current level
Player *mario - pointer towards Mario object 
int currLevel - current level
string output - name of output file
int moves - amount of moves taken so far in the level
*/

#ifndef LEVEL_H
#define LEVEL_H

#include "Level.h"
#include "Player.h"
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Level {
public:
    Level();
    Level(Player *mario, int N, int coin, int empty, int goomba, int koopa, int mushroom, int pipe, int currLevel, string output);
    ~Level();
    void populate(int N, int coin, int empty, int goomba, int koopa, int mush, int pipe);
    void enviroment(char c, int row, int col);
    bool enemy(char c, int row, int col);
    void update(int row, int col);
    void streak(bool result);
    void lose();
    void move();
    void print();
    void writeToFile(char c, bool win);
    char **level;
    int N;
    bool cont;
    Player *mario;
    int currLevel;
    string output;
    int moves;
private:

};

#endif