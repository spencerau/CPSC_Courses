/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA2

Level Class that handles most of the backend logic for the game.

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
*/

#include "Level.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>

//#include "Player.cpp"

using namespace std;

Level::Level() {
    this->level = {};

}

/*
Constructor that sets Mario to the input player pointer, N to N (dimensions), moves to 0, cont to true, and calls
populate(parameters) with the input parameters to populate the char array
*/
Level::Level(Player *mario, int N, int coin, int empty, int goomba, int koopa, int mushroom, int pipe, int currLevel, string output) {
    this->mario = mario;
    this->currLevel = currLevel;
    populate(N, coin, empty, goomba, koopa, mushroom, pipe);
    cont = true;
    this->N = N;
    this->moves = 0;
}

Level::~Level() {

}

/* 
populate() takes an int N (dimensions), int coin, int empty, int goomba, int koopa, int mush, and int pipe and
initializes an array and populates it with the respective char representing different objects listed above and adds a
warp pipe depending on if pipe is 1 or 0 accounting for if it is the last level or not
*/
void Level::populate(int N, int coin, int empty, int goomba, int koopa, int mush, int pipe) {
    int p = 1;
    int w = pipe;
    int b = 1;
    int c = coin;
    int e = empty;
    int g = goomba;
    int k = koopa;
    int m = mush;

    this->level = new char*[N*N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // generate a number between 1 and 8
            int r = rand() % 8 + 1; 
            switch (r) {
                case 1:
                    if (p != 0) {
                        level[i][j] = 'H';
                        p--;
                        mario->row = i;
                        mario->col = j;
                    }
                    break;
                case 2: 
                    if (w != 0) {
                        level[i][j] = 'w';
                        w--;
                    }
                    break;
                case 3: 
                    if (b != 0) {
                        level[i][j] = 'b';
                        b--;
                    }
                    break;
                case 4:
                    if (c != 0) {
                        level[i][j] = 'c';
                        c--;
                    }
                    break;
                case 5:
                    if (e != 0) {
                        level[i][j] = 'x';
                        e--;
                    }
                    break;
                case 6:
                    if (g != 0) {
                        level[i][j] = 'g';
                        g--;
                    }
                    break;
                case 7:
                    if (k != 0) {
                        level[i][j] = 'k';
                        k--;
                    }
                    break;
                case 8:
                    if (m != 0) {
                        level[i][j] = 'm';
                        m--;
                    }
                    break;
            }
        }
    }

}

/* 
writeToFile() takes a char c and bool win and writes the results of each move to the output file. C is the letter of the
target and win is whether or not Mario won against the enemy or lost and is automatically true for an enviroment object
*/
void Level::writeToFile(char c, bool win) {
    ofstream fw(output);
    switch (c) {
        case 'e':
            fw << "The Position is empty";
            break;
        case 'c':
            fw << "Mario collected a coin"; 
            break;
        case 'm':
            fw << "Mario ate a mushroom";
            break;
        case 'w':
            fw << "Mario warped";
            break;
        case 'g':
            fw << "Mario fought a Goomba and ";
            if (win) fw << "won";
            else fw << "lost";
            break;
        case 'k':
            fw << "Mario fought a Koopa and ";
            if (win) fw << "won";
            else fw << "lost";
            break;
        case 'b':
            fw << "Mario fought the level boss and ";
            if (win) fw << "won";
            else fw << "lost";
            break;
    }
    fw << "Lives: " << mario->lives << endl;
    fw << "Coins: " << mario->coins << endl;
    fw.close();
}

/* 
environment() takes a char c, int row, and int col and is a method for when Mario interacts with an environment objects 
such as a coin, mushroom, warp pipe, or empty. Row and Col are the target coordinates, and c is the target letter.
*/
/*
Mario’s Interaction with the Environment
Mario will begin at a random location in the first level, with power PL0, and starts interacting with the environment immediately. Once he has interacted with the current location, he moves on to the next location by moving up, down, left, or right. The direction is chosen randomly with uniform probability (25% each). Interactions with each position occur as follows:
If the position contains nothing, Mario moves on.
If the position contains a coin, Mario adds the coin to his wallet, and then the position contains nothing. Mario moves on.
If the position contains a mushroom, Mario’s power level increases by 1, or stays at PL2 if he’s already in PL2. Once the mushroom is consumed, the position contains nothing, and Mario moves on.
If the position contains a Goomba or Koopa, Mario engages per the rules of a regular enemy, below.
If the position contains the level boss, Mario engages per the rules of a boss, below.
If Mario encounters the warp pipe, he will immediately jump to a random position in the next level without having to beat the current level boss. 
*/
void Level::enviroment(char c, int row, int col) {
    switch (c) {
        case 'x':
            break;
        case 'c':
            mario->coins++;
            if (mario->coins == 20) {
                mario->lives++;
                mario->coins = 0;
            }
            break;
        case 'm':
            if (mario->PL != 0) mario->PL++;
            break;
        case 'w':
            cont = false;
            break;
    }
    update(row, col);
};

/* enemy() takes a char c, int row, and int col and is a method for when Mario interacts with an enemy. Row and Col are the 
target coordinates, and c is the target letter.
*/
/* 
Mario’s Interaction with a Regular Enemy
When Mario encounters a regular enemy, gameplay proceeds as follows:
If the enemy is a Goomba, Mario defeats the enemy with a 80% probability, the position becomes empty, and Mario moves on. If Mario loses (20% probability), his power level is decreased by 1, the Goomba stays in the position, and Mario moves on. The exception is if Mario loses while at PL0, in which case a life is lost. If Mario has another life, he continues at the same location, with PL0. Otherwise, the simulation ends, and the game is lost.
If the enemy is a Koopa, Mario defeats the enemy with a 65% probability, the position becomes empty, and Mario moves on. If Mario loses (35% probability), his power level is decreased by 1, the Koopa stays in the position, and Mario moves on. The exception is if Mario loses while at PL0, in which case a life is lost. If Mario has another life, he continues at the same location, with PL0. Otherwise, the simulation ends, and the game is lost.
If Mario defeats 7 enemies on the same life, he earns another life.
 
Mario’s Interaction with a Boss
When Mario encounters a level boss, gameplay proceeds as follows:
Mario defeats the enemy with a 50% probability, the position becomes empty, and Mario moves on to the next level. If Mario is in the last level, the princess is saved, the game is won, and the simulation is over. If Mario loses (50% probability), his power level is decreased by 2, and Mario attempts to defeat the boss again. The exception is if Mario loses while at PL0 or PL1, in which case a life is lost. If Mario has another life, he continues at the same location, with PL0. Otherwise, the simulation ends, and the game is lost.
*/
bool Level::enemy(char c, int row, int col) {
    int r = rand() % 100; // sets r between 0 and 100% chance of beating enemy
    bool win;
    switch (c) {
        // Goomba
        case 'g':
            if (r >= 20) {
                update(row, col);
                streak(true);
                // print statement
                win = true;
            }
            else { 
                streak(false);
                win = false;
            }
            break;
        // Koopa
        case 'k':
            if (r >= 35) {
                update(row, col);
                streak(true);
                // print statement
                win = true;
            }
            else {
                streak(false);
                win = false;
            }
            break;
        // Boss
        case 'b':
            if (r >= 50) {
                level[mario->row][mario->col] = 'e';
                level[row][col] = 'e';
                mario->row = row;
                mario->col = col;
                mario->streak++;
                if (mario->streak == 7) {
                    mario->lives++;
                    mario->streak = 0;
                }
                cont = false;
                // print statement
                win = true;
            }
            else {
                mario->PL -= 2;
                mario->streak = 0;
                if (mario->PL < 1) {
                    mario->lives--;
                    mario->PL = 0;
                }
                if (mario->lives < 0) mario->alive = false;
                win = false;
            }
            break;
    }
    return win;
};

/* update() takes int row and int col and is a method for if Mario beats the enemy / moves to an item or empty space 
and updates the coordinates
*/ 
void Level::update(int row, int col) {
    level[mario->row][mario->col] = 'e';
    level[row][col] = 'p';
    mario->row = row;
    mario->col = col;
}

/* streak() takes a bool result and is a method to update Mario's win streak against enemies */
void Level::streak(bool result) {
    if (result) {
        mario->streak++;
        if (mario->streak == 7) {
            mario->lives++;
            mario->streak = 0;
        }
    }
    else {
        mario->PL--;
        mario->streak = 0;
        if (mario->PL < 0) {
            mario->lives--;
            mario->PL = 0;
        }
        if (mario->lives < 0) mario->alive = false;
    }
}

/* lose() is a method for if Mario loses to the enemy */
void Level::lose() {
    mario->PL--;
    mario->streak = 0;
    if (mario->PL < 0) {
        mario->lives--;
        mario->PL = 0;
    }
    if (mario->lives < 0) mario->alive = false;
}

/* 
move() is a method that handles how Mario moves using calls from environment() and enemy() to handle the requisite 
logic 
*/
void Level::move() {
    char target;
    // target row and col
    int tRow = mario->row;
    int tCol = mario->col;

    ofstream fw(output);

    int r = rand() % 4; // 0 to 4
    string direct;
    switch (r) {
        // do nothing
        case 0:
            fw << "Mario will STAY PUT";
            direct = "STAY PUT";
            break;
        // left
        case 1: 
            if (mario->col == 0) tCol = N;
            else tCol--;
            direct = "LEFT";
            break;
        // right
        case 2:
            if (mario->col == N) tCol = 0;
            else tCol++;
            direct = "RIGHT";
            break;
        // up
        case 3:
            if (mario->row == 0) tRow = N;
            else tRow--;
            direct = "UP";
            break;
        // down
        case 4:
            if (mario->row == 0) tRow = 0;
            else tRow++;
            direct = "DOWN";
            break;
    }
    if (moves != 0 && direct != "STAY PUT") {
        fw << "Mario will move " << direct << " next" << endl;
        fw << endl;
    }

    print();
    cout << endl;
    fw << "Level: " << currLevel << endl;
    fw << "Position Location: " << mario->row << ", " << mario->col << endl;
    fw << "Power Level: " << mario->PL << endl;

    target = level[tRow][tCol];
    // whether Mario wins the encounter or loses; is automatically true for environment object
    bool win;
    // if target is an enemy
    if (target == 'b' || target == 'g' || target == 'k') {
        win = enemy(target, tRow, tCol);
    }
    // if target is an environment object
    else {
        enviroment(target, tRow, tCol);
        win = true;
    }
    // writes the move taken to log and also prints out char array
    writeToFile(target, win);
    print();
};

/* print() is a method that prints out the character array onto the output file */
void Level::print() {
    ofstream fw(output);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //cout << " | " << level[i][j];
            fw << " | " << level[i][j]; 
        }
        //cout << endl;
        fw << endl;
    }
    fw.close();
}

/*
int main() {
    Player *player = new Player(1);
    Level *level = new Level(player, 4, 4, 2, 4, 1, 2, 1, 1, "test.txt");
    level->print();
    cout << endl;
    while (level->cont) {
        level->move();
        level->print();
        cout << endl;
    }
}
*/