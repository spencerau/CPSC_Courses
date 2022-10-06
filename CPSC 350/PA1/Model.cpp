/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA1

The Model Class
You will build a class named Model that will encode the rules of the Robber language. The class will contain the following public methods:
A default constructor
A default destructor
translateSingleConsonant– takes a single consonant character as input and returns a string representing its encoding in Rövarspråket. Capitalization should be preserved.
translateSingleVowel – takes a single vowel character as input and returns a string representing its encoding in Rövarspråket. Capitalization should be preserved.
*/

#include "Model.h"
#include <string>
#include <iostream>

using namespace std;

Model::Model() {}

Model::~Model() {}

// translateSingleConsonant() takes a char letter and returns a string encode that is the Robber Language translation of the input consonant
string Model::translateSingleConsonant(char letter) {
   string encode;
   encode += letter;
   encode += 'o';
   encode += letter;
   return encode; 
}

// translateSinglevowel() takes a char vowel and returns a string that is the Robber Language translation of the input vowel
string Model::translateSingleVowel(char vowel) {
    string encode;
    encode += vowel;
    return encode;
}
/*
int main() {
    Model *m = new Model();
    cout << m->translateSingleConsonant('s') << endl;
    cout << m->translateSingleVowel('a');

    return 0;
}
*/