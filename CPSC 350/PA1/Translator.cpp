/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA1

The Translator Class
You will build a class named Translator that will translate English sentences to Rövarspråket sentences using the Model class. 
The class will contain the following public methods:
A default constructor
A default destructor
translateEnglishWord – takes a single string representing a single English word as input and returns a string representing the Rövarspråket translation.
translateEnglishSentence – takes a single string representing a single English sentence as input and returns a string representing the Rövarspråket translation. 
Make sure to account for punctuation.

Uses a helper function isVowel() to check if a letter is a vowel or consonant. 
TranslateEnglishWord() translates a single word into the Robber Lanugage, and TranslateEnglishSentence() calls on the previous function to translate an entire sentence.
*/

#include "Translator.h"
#include "Model.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Translator::Translator() {}

Translator::~Translator() {}

// isVowel() is a helper function that takes a char c to check if a letter is a vowel or consonant and returns a boolean value of true or false
bool Translator::isVowel(char c) {
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
        return true;
    }
    // use switch and tolower() instead
    else return false; 
}

// translateEnglishWord() takes a string input (a single word) and translates the single word into Robber language, and returns a string word of the translation
string Translator::translateEnglishWord(string input) {
    string word;
    Model *letter = new Model();
    // for loop that iterates through each letter in the word, checking if it is a puncutation mark, vowel, or consonant and then applying the corresponding function from Model
    for (int i = 0; i < input.length(); i++) {
        if (ispunct(input[i])) {
        // do nothing and go to next iteration of loop
        }
        else if (isVowel(input[i])) {
            word += letter->translateSingleVowel(input[i]);
        }
        else {
            word += letter->translateSingleConsonant(input[i]);
        }    
    }
    delete letter;
    return word;
}
/* translateEnglishSentence() takes a string input sentence and iterates through the stringstream of string input with the default delimiter of a whitespace and calls on 
translateEnglishWord() to concatenate the return string sentence by each translated word and appends the last char punctuation mark from input into sentence and
returns string sentence which will be the Robber Language translated sentence */
string Translator::translateEnglishSentence(string input) {
    string sentence;
    string word;
    stringstream ss(input);
    // uses string stream and a while loop to iterate through the input sentence and separate it by whitespace
    while (ss >> word) {
        sentence += translateEnglishWord(word);
        sentence += " ";
        word = "";
    } 
    // appends the corresponding punction mark at index length-1 at the end of sentence and deletes the last whitespace added
    sentence.pop_back();
    char last = input[input.length()-1];
    if (ispunct(last)) sentence += last;
    return sentence;
}

/*
int main() {
    Translator *t = new Translator();
    string test = t->translateEnglishSentence("This is a test of robber language's capability!");
    cout << test << endl;
    delete t;
    return 0;
}
*/



