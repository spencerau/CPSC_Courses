// Office - models an individual office in the service center

#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "Office.h"

using namespace std;

Office::Office(int size, char type) {
    this->type = type;
    this->line = new ListQueue<Customer*>();
    this->attending = new ListQueue<Customer*>();
    this->office = new DblList<Window*>();
    for (int i = 0; i < size; i++) {
        office->addBack(new Window(type));
    }
    totalIdle = 0;
    maxWindows = size;
    occupWindows = 0;
    totalWait = 0;
    numStudents = 0;
}

Office::~Office() {
    delete line;
    delete attending;
    delete office;
}

// this is when the student goes up to the window and does their crap
void Office::attendStudent() {
    if (occupWindows == maxWindows) return;
    occupWindows++;
    //Window *window = office->get(0);
    //while ()
    attending->add(line->remove());
}

// this is when a student lines up in the back of the line; it calls attendStudent() if any windows are open
void Office::lineUp(Customer *student) {
    student->popOrder();
    line->add(student);
    while (occupWindows < maxWindows) {
        attendStudent();
    }
}

Customer* Office::finish() {
    //totalWait += 
}

void Office::passTime() {
    
}

double Office::getMeanWait() {
    return totalWait / numStudents;
}

int Office::getLongestWait() {
    Window *window;
    int longest = window->getLongest();
    // iterate through Office DLL
    for (int i = 0; i < office->getSize(); i++) {
        window = office->get(i);
        if (window->getLongest() > longest) longest = window->getLongest();
    }
    delete window;
    return longest;
}

double Office::getMeanIdle() {
    Window *window;
    int total = 0;
    for (int i = 0; i < office->getSize(); i++) {
        window = office->get(i);
        total += window->getIdle();
    }
    delete window;
    return total / maxWindows;
}

int Office::getLongestIdle() {
    Window *window;
    int idle = 0;
    for (int i = 0; i < office->getSize(); i++) {
        window = office->get(i);
        if (window->getIdle() > idle) idle = window->getIdle();
    }
    delete window;
    return idle;
}

int Office::getIdleOver5() {
    Window *window;
    int idleOver5 = 0;
    for (int i = 0; i < office->getSize(); i++) {
        window = office->get(i);
        if (window->getIdle() >= 5) idleOver5++;
    }
    delete window;
    return idleOver5;
}