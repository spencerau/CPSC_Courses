#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "Customer.h"

using namespace std;

Window::Window(char type) {
    this->type = type;
    this->students = 0;
    this->totalWait = 0;
    this->idle = 0;
    this->currWait = 0;
    this->timeNeeded = 0;
    this->longest = 0;
    this->occupied = false;
    currTime = 0;
    finished = false;
}

Window::~Window() {
    delete curStudent;
}

void Window::setStudent(Customer *student) {
    this->curStudent = student;
    curStudent->attend();
    //cout << "Student.attend() worked" << endl;
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

int Window::getLongest() {
    return longest;
}

int Window::getIdle() {
    return idle;
}

Customer* Window::getStudent() {
    return curStudent;
}

int Window::getTotalWait() {
    return totalWait;
}

bool Window::isOccupied() {
    return occupied;
}

void Window::finish() {
    totalWait += curStudent->getCurWait();
    curStudent->finish();
    occupied = false;
    
    currTime = 0;
    finished = true;
}

void Window::passTime() {
    // is idle
    if (!occupied) {
        idle++;
        //cout << "Window at Office " << type << " is currently idle" << endl;
    }
    // occupied
    else {
        curStudent->passTime(); // its this line that is fucky
        cout << "Current Time at Window = " << currTime << endl;
        cout << "Time Needed at Window = " << timeNeeded << endl;
        currTime++;
        if (currTime >= timeNeeded) finish();
    }
}