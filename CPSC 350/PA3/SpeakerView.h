#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MStack.h"

using namespace std;

class SpeakerView {
public:
    SpeakerView(int size, char o);
    ~SpeakerView();
    void readFile(string fileName);
    void getCol(string input);
private:
    MonoStack<double> *stack;
    //MStack<double> *stack;
    //string filename;
    int col;
};


#endif