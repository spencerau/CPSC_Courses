/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA3

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

*/

#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
Constructor that takes an int size that represents initial size and char o 
that is a flag for whether it is monotonically increasing or decreasing. Initializes a new MonoStack<double>
for stack and sets col to -1
*/
SpeakerView::SpeakerView(int size, char o) {
    this->stack = new MonoStack<double>(size, o);
    this->col = -1;
}

/*
Deconstructor that deletes the stack
*/
SpeakerView::~SpeakerView() {
    delete stack;
}

/*
getCol() takes a string input of the filename and gets the columns from the file and sets col to 
the number of columns
*/
void SpeakerView::getCol(string input) {
    ifstream read(input);
    string line;
    while (getline(read, line)) {
        this->col++;
    }
    read.close();
}
/*
readFile() takes a string input that is the filename. It calls getCol(input) to set col to the amount of columns in the file. 
It then uses a for loop checking if j == i, where i is the column you're checking for, and j is the column its iterating through,
in order to push all elements of a single column i onto the stack. It then prints out the amount of people in Column i that can
see the speaker by calling stack->size() and lists out their heights by calling pop() until the stack is empty. It then resets 
the read ifstream to check for the next column i
*/
void SpeakerView::readFile(string input) {
    ifstream read(input);
    double num;
    string line;
    // i is the current column
    getCol(input);
    for (int i = 0; i < col; i++) {
        while (getline(read, line)) {
            // current column to check
            int j = 0;
            istringstream ss(line);
            while (ss >> num) {
                if (i == j) {
                    //stack->printStack();
                    stack->push(num);
                }
                j++;
            }
        }
        cout << "Column " << i << ": " << stack->size() << " people can see. Their heights are: ";
        //cout << endl;
        while (!stack->isEmpty()) {
            //stack->printStack();
            cout << stack->pop();
            if (stack->size() != 0) cout << ", ";
            else if (stack->size() == 0) cout << " inches.";
        }
        cout << endl;
        // reset read stream
        read.clear();
        read.seekg(0);
    }
    cout << "." << endl;
    read.close();
}