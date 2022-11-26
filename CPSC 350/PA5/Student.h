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

Student(int id, string name, string level, string major, double GPA, int advisor) - constructor that takes an int id, string name, string level, 
string major, double gpa, and int advisor and sets the relevant fields inside student

int getid() - returns id
int getAdvisor() - returns the advisor id
void changeAdvisor(int advisor) - takes an int advisor and changes the advisor field
void printInfo() - prints out the info of the student
void printToFile(ofstream &writer) - writes the info of the student onto runLog.txt

bool operator == (Student &rhs) - overload == to compare id values
bool operator > (Student &rhs) - overload > to compare id values
bool operator < (Student &rhs) - overload < to compare id values
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>

using namespace std;

class Student {
public:
    Student(int id, string name, string level, string major, double GPA, int advisor);
    ~Student();
    int getid();
    int getAdvisor();
    void changeAdvisor(int advisor);
    void printInfo();
    void printToFile(ofstream &writer);
    // the overloading might be wrong
    bool operator == (Student &rhs);
    bool operator > (Student &rhs);
    bool operator < (Student &rhs);
private:
    int id;
    string name;
    string level;
    string major;
    double GPA;
    int advisor;
};


#endif