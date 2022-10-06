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