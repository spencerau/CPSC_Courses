#include "MonoStack.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

SpeakerView::SpeakerView() {
    //this->filename = filename;
    this->stack = new MonoStack<double>(1, 'd');
}

SpeakerView::~SpeakerView() {
    delete stack;
}

void SpeakerView::readFile(string fileName) {
    ifstream read(fileName);
}