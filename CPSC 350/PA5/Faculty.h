/*
Faculty records contain an integer Faculty ID, a string name, a string level (lecturer, assistant prof, associate prof, etc.), a string department, 
and a list of integers corresponding to all of the faculty member’s advisees’ ids. These are the only fields the class contains.
*/

#ifndef FACULTY_H
#define FACULTY_H

#include <string>

using namespace std;

class Faculty {
public:
    Faculty();
    ~Faculty();
private:
    int id;
    string name;
    string level;
    string dept;

};

#endif 
