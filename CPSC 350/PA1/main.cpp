/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA1

In addition to the above, you should provide a main method in a file called main.cpp. It should only contain a main method. The main method will be invoked with 2 command line arguments representing the input (English) file and the output (Robber Language) file as strings. Your main method should do the following:
Instantiate a FileProcessor
Translate the provided input file to Rövarspråket using the file processor.
Exit
*/

#include "FileProcessor.h"
#include <string>
#include <iostream>

using namespace std;

// The Main Function takes an int amount of arguments and a char array of the individual arguments from the command line, and returns a 0
int main(int argc, char **argv) {
    FileProcessor *fp = new FileProcessor();
    fp->processFile(argv[1], argv[2]);
    delete fp;
    return 0;
}