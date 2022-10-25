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
        curStudent->passTime();
        if (curStudent->getAttending() >= timeNeeded) {
            finish();
        }
    }
}