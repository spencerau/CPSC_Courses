#include <cstdlib>
#include <iostream>
#include "Window.h"

using namespace std;

Window::Window(char type) {
    this->type = type;
    this->students = 0;
    this->totalTime = 0;
    this->idle = 0;
    this->currWait = 0;
    this->timeNeeded = 0;
    this->longest = 0;
    this->occupied = false;
}

Window::~Window() {
}

bool Window::passTime() {
    if (occupied) {
        if (++currWait == timeNeeded) {
            currWait = 0;
            return true;
        }
        return false;
    }
    else {
        idle++;
        return false;
    }
}

double Window::getAvg() {
    return totalTime / students;
}

void Window::setStudent(Customer *student) {
    this->currentStudent = student;
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
    occupied = true;
}

int Window::getLongest() {
    return longest;
}

int Window::getIdle() {
    return idle;
}