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
*/

#include <string>
#include "Faculty.h"
#include <iostream>

using namespace std;

/*
Faculty(int id, string name, string level, string dept) - contructor that takes an int id, string name, string level, and string dept and sets the
relevant fields
*/
Faculty::Faculty(int id, string name, string level, string dept) {
    this->id = id;
    this->name = name;
    this->level = level;
    this->dept = dept;
    this->students = new DblList<int>;
}

// ~Faculty() - deconstructor that deletes the list of advisees
Faculty::~Faculty() {
    delete this->students;
}

// int getid() - returns id
int Faculty::getid() {
    return id;
}

// void addStudent(int id) - takes an int id and adds that id to the advisees list
void Faculty::addStudent(int id) {
    students->addBack(id);
}

// void removeStudent(int id) - takes an int id and removes that id from the advisees list
void Faculty::removeStudent(int id) {
    for (int i = 0; i < students->getSize(); i++) {
        if (students->get(i) == id) students->remove(i);
        else cout << "Advisee " << i << ": " << students->get(i) << endl;
    }
}

// bool hasStudent(int id) - takes an int id and checks if advisees list has that id
bool Faculty::hasStudent(int id) {
    if (students->contains(id)) return true;
    else return false;
}

// void printInfo() - prints out the info for the faculty
void Faculty::printInfo() {
    //cout << "test fuck" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Level: " << level << endl;
    cout << "Department: " << dept << endl;
    cout << "Advisees: " << endl;
    for (int i = 0; i < students->getSize(); i++) {
        cout << students->get(i) << endl;
    }
    cout << endl;
}

// void printToFile(ofstream &writer) - takes an ofstream &writer and writes the info to runLog.txt
void Faculty::printToFile(ofstream &writer) {
    writer << "Name: " << name << endl;
    writer << "ID: " << id << endl;
    writer << "Level: " << level << endl;
    writer << "Department: " << dept << endl;
    writer << "Advisees: " << endl;
    // this prints out a list of the advisees only be ID
    for (int i = 0; i < students->getSize(); i++) {
        writer << students->get(i) << endl;
    }
    writer << endl;
}

// DblList<int>* getAdvisees() - returns the advisees list
DblList<int>* Faculty::getAdvisees() {
    return students;
}

// bool operator == (Faculty &rhs) - overload == to compare id values
bool Faculty::operator == (Faculty &rhs) {
    return id == rhs.getid();
}

// bool operator > (Faculty &rhs) - overload > to compare id values
bool Faculty::operator > (Faculty &rhs) {
    return id > rhs.getid();
}

// bool operator < (Faculty &rhs) - overload < to compare id values
bool Faculty::operator < (Faculty &rhs) {
    return id < rhs.getid();

}