/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA3

Header File for SpeakerView Class

Functions:
SpeakerView(int size, char o) - Constructor that takes an int size that represents initial size and char o 
that is a flag for whether it is monotonically increasing or decreasing. Initializes a new MonoStack<double>
for stack and sets col to 0
~SpeakerView() - Deconstructor that deletes the stack

readFile() -  readFile() takes a string input that is the filename. It calls getCol(input) to set col to the amount of columns in the file. 
It then uses a for loop checking if j == i, where i is the column you're checking for, and j is the column its iterating through,
in order to push all elements of a single column i onto the stack. It then prints out the amount of people in Column i that can
see the speaker by calling stack->size() and lists out their heights by calling pop() until the stack is empty. It then resets 
the read ifstream to check for the next column i
getCol() - getCol() takes a string input of the filename and gets the columns from the file and sets col to 
the number of columns

Variables:
MonoStack<double> *stack - MonoStack object that represents the monotonic stack
int col - int variable that represents the amount of columns in the file
*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class SpeakerView {
public:
    SpeakerView(int size, char o);
    ~SpeakerView();
    void readFile(string fileName);
    void getCol(string input);
private:
    MonoStack<double> *stack;
    int col;
};


#endif