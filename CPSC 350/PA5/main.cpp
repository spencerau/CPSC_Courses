/*
Spencer Au
ID: 002385256
spau@chapman.edu

Partner:
Ben Fellows
bfellows@chapman.edu

CPSC 350 - Section 2
PA5

main.cpp file that creates a new Interface pointer interface, calls Interface.run(), and closes it when run terminates upon selection of option 11
*/

#include "Interface.h"

using namespace std;

int main() {
    Interface *interface = new Interface();
    interface->run();
    delete interface;
}