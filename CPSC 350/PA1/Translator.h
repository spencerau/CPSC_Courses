/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA1

Header File for Translator class. Uses a helper function isVowel() to check if a letter is a vowel or consonant. 
TranslateEnglishWord() translates a single word into the Robber Lanugage, and TranslateEnglishSentence() calls on the previous function to translate an entire sentence.
*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Translator.h"
#include "Model.h"
#include <string>

using namespace std;

class Translator {
public:
    Translator();
    ~Translator();
    bool isVowel(char c);
    string translateEnglishWord(string input);
    string translateEnglishSentence(string input);
private:

};

#endif
