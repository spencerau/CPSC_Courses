#include "Enemy.h"
#include <string>
#include <iostream>

using namespace std;

Enemy::Enemy() {
    //type = 1;
    row = 0;
    col = 0;
}

Enemy::Enemy(int row, int col) {
    //this->type = enemy;
    this->row = row;
    this->col = col;
}

Enemy::~Enemy () {

}
