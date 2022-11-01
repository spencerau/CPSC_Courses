/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA4

CPP File for Window that models a single window in one of the offices


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
*/

#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "Customer.h"

using namespace std;

/*
Window(char type) - constructor that takes a char type as parameter and sets it to this->type; also initializes other variables
*/
Window::Window(char type) {
    this->type = type;
    this->students = 0;
    this->idle = 0;
    this->timeNeeded = 0;
    this->occupied = false;
    currTime = 0;
    finished = false;
}

Window::~Window() {
    delete curStudent;
}

/*
void setStudent(Customer *student) - sets the parameter student as the curStudent variable, calls Customer.attend(), sets occupied as true, and sets
timeNeeded as the requisite time from the Student
*/
void Window::setStudent(Customer *student) {
    this->curStudent = student;
    curStudent->attend();
    switch (type) {
        case 'C':
            timeNeeded = student->getCash();
            break;
        case 'F':
            timeNeeded = student->getFinAid();
            break;
        case 'R':
            timeNeeded = student->getRegist();
            break;
    }
    occupied = true;
}

int Window::getIdle() {
    return idle;
}

Customer* Window::getStudent() {
    return curStudent;
}

bool Window::isOccupied() {
    return occupied;
}

/*
void finish() - simulates a window finishing a student; sets occupied to false, currTime to 0, and finished to true
*/
void Window::finish() {
    curStudent->finish();
    occupied = false;
    currTime = 0;
    finished = true;
}

/*
void passTime(); - simulates one minute passing; if the window is not occupied, iterates idle, otherwise iterates currTime, 
calls currStudent.passTime(), and if the currTime >= timeNeeded then it calls finish()
*/
void Window::passTime() {
    // is idle
    if (!occupied) {
        idle++;
        //cout << "Window at Office " << type << " is currently idle" << endl;
    }
    // occupied
    else {
        curStudent->passTime();
        //cout << "Current Time at Window = " << currTime << endl;
        //cout << "Time Needed at Window = " << timeNeeded << endl;
        currTime++;
        if (currTime >= timeNeeded) finish();
    }
}