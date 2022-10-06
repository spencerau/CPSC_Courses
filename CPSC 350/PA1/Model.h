/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA1

This is the header file for the Model class. It has a regular constructor and destructor and has the methods translateSingleConsonant() and translateSingleVowel
*/

#ifndef MODEL_H
#define MODEL_H

#include "Model.h"
#include <string>

using namespace std;

class Model {
public:
    Model();
    ~Model();
    string translateSingleConsonant(char letter);
    string translateSingleVowel(char vowel);
private:

};

#endif