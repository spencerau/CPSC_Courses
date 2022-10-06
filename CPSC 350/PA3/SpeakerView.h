#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class SpeakerView {
public:
    SpeakerView(int size, char o);
    ~SpeakerView();
    void readFile(string fileName);

private:
    MonoStack<double> *stack;
    //string filename;
};


#endif