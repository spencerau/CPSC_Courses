/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA1

The FileProcessor Class
You will build a class named FileProcessor that will take txt files containing English text and produce a html file containing the equivalent Rövarspråket translation that can be viewed in a standard web browser. 
The class will contain the following public methods:
A default constructor
A default destructor
processFile – takes a string representing the input file  (English) and a string representing the output file (where the Rövarspråket translation will be written). This method has a void return type. 
The method should produce a html file that has the original English text in bold followed by an empty line, followed by the Rövarspråket translation in italics. 

The FileProcessor class has a default constructor and destructor and uses one function processFile() that takes the name of an input and output file.
It reads the name of the input file, uses ifstream to read the content, and uses ofstream to write into the html output file
*/

#include "FileProcessor.h"
#include "Translator.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

FileProcessor::FileProcessor() {

}

FileProcessor::~FileProcessor() {

}

/* processFile() takes a string input txt filename and string output html filename, reads from input and writes into output, and returns void
Writes in bold on the first line the original string sentence, an empty line on the second line, and on the third line, the translated Robber Language Sentence */
void FileProcessor::processFile(string input, string output) {
    string sentence;
    string translate;
    Translator *t = new Translator();

    // ifstream Object used to read from txt file input
    ifstream readStream(input);
    // ofstream Object used to write into an HTML file
    ofstream writeStream(output);
    // iterator i that is used in conjunction with <h1>, <h2>, etc 
    int i = 1;

    writeStream << "<html>" << endl;
    writeStream << "<body>" << endl;
    // while loop that reads each line from readStream and writes the sentence in bold into the html file
    while (getline(readStream, sentence)) {
        writeStream << "<h" << i << "><b>" << sentence << "</b></h" << i << ">" << endl;
        i++;
    }

    // resets readStream to start from the beginning of the file
    readStream.clear();
    readStream.seekg(0);

    // writes an empty line to the html file
    writeStream << "<h" << i << ">" << "</h" << i << ">" << endl;
    i++;

    // while loop that reads each line from readStream and writes the translated sentence into the html file
    while (getline(readStream, sentence)) {
        // calls on Translator::translateEnglishSentence() to translate sentence into the Robber Language, and assigns it to translate
        translate = t->translateEnglishSentence(sentence);
        writeStream << "<h" << i << "><i>" << translate << "</i></h" << i << ">" << endl;
        i++;
    }
    writeStream << "</body>" << endl;
    writeStream << "</html>" << endl;

    readStream.close();
    writeStream.close();
    delete t;
}

/*
int main() {
    FileProcessor *fp = new FileProcessor();
    fp->processFile("original.txt", "output.html");
    return 0;
}
*/