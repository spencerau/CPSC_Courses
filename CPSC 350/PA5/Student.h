/*
Student records will be stored in a Student class.  Student records contain a unique student ID (an integer), a string name field, 
a string level field (Freshman, Sophomore, etc.), a string major field, a double GPA field, and an integer advisor field, which will contain 
the Faculty ID of their advisor. These are the only fields the class contains.
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
public:
    Student(string name, string level, string major, double GPA, int advisor);
    ~Student();
    int getID();
    int getAdvisor();
    void changeAdvisor(int advisor);
    void printInfo();
private:
    int studentID;
    string name;
    string level;
    string major;
    double GPA;
    int advisor;
};


#endif