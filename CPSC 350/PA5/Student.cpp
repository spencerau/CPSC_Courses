/*
Spencer Au
ID: 002385256
spau@chapman.edu

Partner:
Ben Fellows
bfellows@chapman.edu

CPSC 350 - Section 2
PA5

Student records will be stored in a Student class.  Student records contain a unique student ID (an integer), a string name field, 
a string level field (Freshman, Sophomore, etc.), a string major field, a double GPA field, and an integer advisor field, which will contain 
the Faculty ID of their advisor. These are the only fields the class contains.
*/

#include <string>
#include "Student.h"
#include <iostream>

using namespace std;

/*
Student(int id, string name, string level, string major, double GPA, int advisor) - constructor that takes an int id, string name, string level, 
string major, double gpa, and int advisor and sets the relevant fields inside student
*/
Student::Student(int id, string name, string level, string major, double GPA, int advisor) {
    this->id = id;
    this->name = name;
    this->level = level;
    this->major = major;
    this->GPA = GPA;
    this->advisor = advisor;
}

Student::~Student() {

}

// int getid() - returns id
int Student::getid() {
    //std::cout << "getid called, returning: " << id << "\n";
    return id;
}

// int getAdvisor() - returns the advisor id
int Student::getAdvisor() {
    return advisor;
}

// void changeAdvisor(int advisor) - takes an int advisor and changes the advisor field
void Student::changeAdvisor(int advisor) {
    this->advisor = advisor;
}

// void printInfo() - prints out the info of the student
void Student::printInfo() {
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "Level: " << level << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Advisor: " << advisor << endl;
    cout << endl;
}

// void printToFile(ofstream &writer) - writes the info of the student onto runLog.txt
void Student::printToFile(ofstream &writer) {
    writer << "Student Name: " << name << endl;
    writer << "Student ID: " << id << endl;
    writer << "Level: " << level << endl;
    writer << "Major: " << major << endl;
    writer << "GPA: " << GPA << endl;
    writer << "Advisor: " << advisor << endl;
    writer << endl; 
}

// bool operator == (Student &rhs) - overload == to compare id values
bool Student::operator == (Student &rhs) {
    return id == rhs.getid();
}

// bool operator > (Student &rhs) - overload > to compare id values
bool Student::operator > (Student &rhs) {
    return id > rhs.getid();
}

// bool operator < (Student &rhs) - overload < to compare id values
bool Student::operator < (Student &rhs) {
    return id < rhs.getid();

}