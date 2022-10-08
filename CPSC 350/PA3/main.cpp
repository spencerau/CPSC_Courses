/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA3

main.cpp file for PA3. It checks if the arguments are != 1, and returns -1. If false, then it creates a new SpeakerView object
with the parameters of initial size 1 and a decreasing monotonic stack. It then calls SpeakerView->readFile(argv[0]) where
argv[0] is the name of the file to be read from
*/

#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char **argv) {
    if (argc != 1) return -1;
    SpeakerView *speaker = new SpeakerView(1, 'd');
    speaker->readFile(argv[0]);
}


/*
int main() {
	//MonoStack *stack = new MonoStack(1, 'd');
	MonoStack<double> *stack = new MonoStack<double>(1, 'd');
	stack->push(1);
    // will pop 1 and then push 2
	stack->push(2);

    // will pop 2 and push 3
	stack->push(3);
    // since 2 < 3 it just pushes 2 = 2, 3
	stack->push(2);
    // since 1 < 2 && 1 < 3 it just pushes 1 - 1, 2, 3
    stack->push(1);
    stack->printStack();
    cout << "Size: "  << stack->size() << endl;
    cout << "test" << endl;
	return 1;
} 
*/