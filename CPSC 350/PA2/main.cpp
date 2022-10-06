/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA2

*/

#include "World.h"
#include <fstream>
#include <iostream>

using namespace std;

/* assumes that the first arg argv[0] is the name of the file to be read from 
and the second argv[1] is the name of the output file) */
int main(int argc, char **argv) {
    ifstream read(argv[0]);
    int arr[8];
    int number;
    int i = 0;
    while (read >> number) {
        arr[i] = number;
    }
    // check that percentages sum up to 100
    if (arr[3] + arr[4] + arr[5] + arr[6] + arr[7] != 100) {
        return -1;
    }
    World *world = new World(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], argv[1]);
    world->play();
}
