/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA2

The World
The world consists of a number of levels, L, which will be provided at runtime. To finish the game, Mario must navigate 
from level 1 to level L by defeating intermediate bosses, and defeat the final boss in level L. If Mario runs out of 
lives before this task is accomplished, the game is lost.
*/

#include "Player.h"
#include "Level.h"
#include "World.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

World::World() {

}

/* 
Constructor intializes a new Player object, and uses an int pipe variable to determine whether or not to create 
a warp pipe contingent on it being the last level or not. It then populates Level **world with a new Level object, 
and sets levels to L, output to the output file name, and moves to 0
*/
World::World(int L, int N, int lives, int coin, int empty, int goomba, int koopa, int mushroom, string output) {
    mario = new Player(lives);
    int pipe = 1;

    for (int i = 0; i < levels; i++) {
        if (i + 1 == levels) pipe = 0;
        world[i] = new Level(mario, N, coin, empty, goomba, koopa, mushroom, pipe, i, output);
    }
    this->levels = L;
    this->output = output;
    int moves = 0;
}

World::~World() {

}

/* 
play() continues the game as long as Player mario is alive, calling the function Level->move() and adding the total moves
in each Level when the level is finished to moves in World. It prints out the final result of the game and the total number
of moves taken
*/
void World::play() {
    ofstream fw(output);
    while (mario->alive) {
        for (int i = 0; i < levels; i++) {
            while (world[i]->cont) {
                world[i]->move();
            }
            moves += world[i]->moves;
        }
    }
    if (!mario->alive) {
        fw << "Mario lost the game" << endl;
    }
    else {
        fw << "Mario won the game" << endl;
    }
    fw << "Total Number of Moves: " << moves << endl;
}
