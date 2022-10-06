#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

SpeakerView::SpeakerView(int size, char o) {
    //this->filename = filename;
    this->stack = new MonoStack<double>(size, o);
}

SpeakerView::~SpeakerView() {
    delete stack;
}

void SpeakerView::readFile(string input) {
    ifstream read(input);
    double num;
    string line;
    int i = 0;
    while (getline(read, line)) {
        istringstream ss(line);
        while (ss >> num) {
            stack->push(num);
        }
        cout << "Column " << i << ": " << stack->size() << " people can see." << endl;
        i++;
        delete stack;
        stack = new MonoStack<double>(1, 'd');
    }
    read.close();
}