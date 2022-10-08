/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA3

main.cpp file for PA3. It checks if the arguments are != 2, and returns -1. If false, then it creates a new SpeakerView object
with the parameters of initial size 1 and a decreasing monotonic stack. It then calls SpeakerView->readFile(argv[1]) where
argv[1] is the name of the file to be read from
*/

#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char **argv) {
    if (argc != 2) return -1;
    SpeakerView *speaker = new SpeakerView(1, 'd');
    speaker->readFile(argv[1]);
}
