/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA1

The FileProcessor class has a default constructor and destructor and uses one function processFile() that takes the name of an input and output file.
It reads the name of the input file, uses ifstream to read the content, and uses ofstream to write into the html output file
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "FileProcessor.h"
#include "Translator.h"
#include <string>

using namespace std;

class FileProcessor {
public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string input, string output);
private:

};

#endif