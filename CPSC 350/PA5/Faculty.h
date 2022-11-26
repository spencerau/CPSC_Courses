/*
Spencer Au
ID: 002385256
spau@chapman.edu

Partner:
Ben Fellows
bfellows@chapman.edu

CPSC 350 - Section 2
PA5

Faculty records contain an integer Faculty ID, a string name, a string level (lecturer, assistant prof, associate prof, etc.), a string department, 
and a list of integers corresponding to all of the faculty member’s advisees’ ids. These are the only fields the class contains.

Faculty(int id, string name, string level, string dept) - contructor that takes an int id, string name, string level, and string dept and sets the
relevant fields

~Faculty() - deconstructor that deletes the list of advisees

int getid() - returns id
void addStudent(int id) - takes an int id and adds that id to the advisees list
void removeStudent(int id) - takes an int id and removes that id from the advisees list
bool hasStudent(int id) - takes an int id and checks if advisees list has that id
void printInfo() - prints out the info for the faculty
void printToFile(ofstream &writer) - takes an ofstream &writer and writes the info to runLog.txt

bool operator == (Faculty &rhs) - overload == to compare id values
bool operator > (Faculty &rhs) - overload > to compare id values
bool operator < (Faculty &rhs) - overload < to compare id values

DblList<int>* getAdvisees() - returns the advisees list
*/

#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "DblList.h"
#include <fstream>

using namespace std;

class Faculty {
public:
    Faculty(int id, string name, string level, string dept);
    ~Faculty();
    int getid();
    void addStudent(int id);
    void removeStudent(int id);
    bool hasStudent(int id);
    void printInfo();
    void printToFile(ofstream &writer);
    bool operator == (Faculty &rhs);
    bool operator > (Faculty &rhs);
    bool operator < (Faculty &rhs);
    DblList<int>* getAdvisees();
private:
    int id;
    string name;
    string level;
    string dept;
    DblList<int> *students;
};

#endif 
