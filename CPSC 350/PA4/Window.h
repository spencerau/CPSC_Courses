// Window - models a single window in one of the offices

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
    //void enqueue(Customer student);
    //void dequeue();
    bool passTime();
    double getAvg();
    void setStudent(Customer *student);
private:
    char type;
    int students;
    int totalTime;
    int idle;
    int currWait;
    int timeNeeded;
    bool occupied;

    Customer *currentStudent;
};

// move the queue line to Office.h/cpp

Window::Window(char type) {
    this->type = type;
    this->students = 0;
    this->totalTime = 0;
    this->idle = 0;
    this->currWait = 0;
    this->timeNeeded = 0;
    this->occupied = false;
}

Window::~Window() {
}

/*
void Window::enqueue(Customer student) {
    queue->add(student);
    currWait = 0;
}

void Window::dequeue() {
    students++;
    totalTime += queue->peek().getWait();
    queue->remove();
    currWait = 0;
}
*/

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
    /*
    if (queue->isEmpty()) idle++;
    else {
        currWait++;
        for (int i = 0; i < queue->size(); i++) {
            Customer student = queue->peek();
            student.passTime();
            student = student.getNext();
        }
        switch (type) {
            case 'f':
                if (currWait >= queue->peek().getFinAid()) dequeue();
                break;
            case 'r':
                if (currWait >= queue->peek().getRegist()) dequeue();
                break;
            case 'c':
                if (currWait >= queue->peek().getCash()) dequeue();
                break;
        }
    }
    */
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

#endif