#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MStack.h"

using namespace std;

SpeakerView::SpeakerView(int size, char o) {
    //this->filename = filename;
    this->stack = new MonoStack<double>(size, o);
}

SpeakerView::~SpeakerView() {
    delete stack;
}

void SpeakerView::getCol(string input) {
    ifstream read(input);
    string line;
    while (getline(read, line)) {
        this->col++;
    }
    read.close();
}

void SpeakerView::readFile(string input) {
    ifstream read(input);
    double num;
    string line;
    this->col = 0;
    // i is the current column
    getCol(input);
    for (int i = 0; i < col; i++) {
        while (getline(read, line)) {
            // current column to check
            int j = 0;
            istringstream ss(line);
            while (ss >> num) {
                if (i == j) stack->push(num);
                j++;
            }
        }
        cout << "Column " << i << ": " << stack->size() << " people can see. Their heights are: ";
        while (!stack->isEmpty()) {
            cout << stack->pop() << ", ";
        }
        // reset read stream
        read.clear();
        read.seekg(0);
    }
    cout << "." << endl;
    /*
    while (getline(read, line)) {
        istringstream ss(line);
        while (ss >> num) {
            stack->push(num);
        }
        cout << "Column " << i << ": " << stack->size() << " people can see. Their heights are: ";
        while (!stack->isEmpty()) {
            cout << stack->pop() << ", ";
        }
        cout << "." << endl;
        i++;
        //delete stack;
        //stack = new MonoStack<double>(1, 'd');
    }
    */
    read.close();
}

int main() {
    SpeakerView *speaker = new SpeakerView(1, 'd');
    speaker->readFile("test.txt");
}