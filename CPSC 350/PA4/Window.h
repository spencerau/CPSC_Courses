/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA4

Header File for Window that models a single window in one of the offices


Functions:
Window(char type) - constructor that takes a char type as parameter and sets it to this->type; also initializes other variables
~Window(); - deconstructor

void setStudent(Customer *student); - sets the parameter student as the curStudent variable, calls Customer.attend(), sets occupied as true, and sets
timeNeeded as the requisite time from the Student

Customer* getStudent(); - returns the curStudent
int getIdle(); - accessor for idle; time spent idle
bool isOccupied(); - whether the window is currently occupied

void finish(); - simulates a window finishing a student; sets occupied to false, currTime to 0, and finished to true

void passTime(); - simulates one minute passing; if the window is not occupied, iterates idle, otherwise iterates currTime, 
calls currStudent.passTime(), and if the currTime >= timeNeeded then it calls finish()

Variables:
char type; - represents the type of office
int students; - represents the num of students the window has seen
int idle; - represents the time spent idle
bool occupied; - if the window is occupied or not
int currTime; - current time spent attending to student
int timeNeeded; - time needed for current student
Customer *curStudent; - current student at window

*/

#ifndef WINDOW_H
#define WINDOW_H

#include <cstdlib>
#include <iostream>
#include "ListQueue.h"
#include "Customer.h"

using namespace std;

class Window {
public:
    Window(char type);
    ~Window();
    void setStudent(Customer *student);
    Customer* getStudent();
    int getIdle();
    bool isOccupied();
    void finish();
    void passTime();
    bool finished;
private:
    char type;
    int students;
    int idle;
    bool occupied;
    int currTime;
    int timeNeeded;

    Customer *curStudent;
};

#endif