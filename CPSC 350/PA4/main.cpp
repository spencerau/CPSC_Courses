/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA3

main.cpp file for PA4
*/

#include "ServiceCenter.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    //if (argc != 2) return -1;
    //ServiceCenter *serviceCenter = new ServiceCenter(argv[1]);
    ServiceCenter *serviceCenter = new ServiceCenter("test.txt");
    serviceCenter->printResult();
}