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
    maxWindows = size;
    occupWindows = 0;
}

Office::~Office() {
    delete line;
    delete attending;
}

// this is when the student goes up to the window and does their crap
void Office::attendStudent() {
    if (occupWindows == maxWindows) return;
    occupWindows++;
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


void Office::passTime() {
    
}