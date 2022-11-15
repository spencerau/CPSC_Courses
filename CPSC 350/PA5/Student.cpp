/*
Student records will be stored in a Student class.  Student records contain a unique student ID (an integer), a string name field, 
a string level field (Freshman, Sophomore, etc.), a string major field, a double GPA field, and an integer advisor field, which will contain 
the Faculty ID of their advisor. These are the only fields the class contains.
*/

#include <string>
#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string name, string level, string major, double GPA, int advisor) {
    this->name = name;
    this->level = level;
    this->major = major;
    this->GPA = GPA;
    this->advisor = advisor;
}

Student::~Student() {

}

int Student::getID() {
    return studentID;
}

int Student::getAdvisor() {
    return advisor;
}

void Student::changeAdvisor(int advisor) {
    this->advisor = advisor;
}

void Student::printInfo() {
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Level: " << level << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << GPA << endl;
}