#ifndef ENEMY_H
#define ENEMY_H

#include "Enemy.h"
#include <string>

using namespace std;

class Enemy {
public:
    Enemy();
    Enemy(int row, int col);
    enum type {goomba, koopa, boss};
    int row;
    int col;
private:

};

#endif