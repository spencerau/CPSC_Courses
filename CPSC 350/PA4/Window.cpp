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
}

Window::~Window() {
    delete curStudent;
}

void Window::setStudent(Customer *student) {
    this->curStudent = student;
    curStudent->attend();
    cout << "Student.attend() worked" << endl;
    timeNeeded = curStudent->getTimeNeeded();
    /*
    switch (type) {
        case 'c':
            timeNeeded = student->getCash();
            break;
        case 'f':
            timeNeeded = student->getFinAid();
            break;
        case 'r':
            timeNeeded = student->getRegist();
            break;
    }
    */
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
}

void Window::passTime() {
    // is idle
    if (!occupied) idle++;
    // occupied
    else {
        cout << "before curStudent.passTime()" << endl;
        curStudent->passTime(); // its this line that is fucky
        cout << "Student at this Window passTime() worked" << endl;
        if (curStudent->getAttending() >= timeNeeded) {
            cout << "before Customer.finish()" << endl;
            finish();
                    cout << "Student finished" << endl;

        }
    }
}