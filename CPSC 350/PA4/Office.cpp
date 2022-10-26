// Office - models an individual office in the service center

#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "Office.h"

using namespace std;

Office::Office(int size, char type) {
    this->type = type;
    this->line = new ListQueue<Customer*>();
    this->finished = new ListQueue<Customer*>();
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
    delete finished;
    delete office;
}

ListQueue<Customer*>* Office::getFinished() {
    return finished;
}

// this is when the student goes up to the window and does their crap
void Office::attendStudent() {
    if (occupWindows == maxWindows) return;
    occupWindows++;
    for (int i = 0; i < office->getSize(); i++) {
        if (!office->get(i)->isOccupied()) {
            office->get(i)->setStudent(line->remove());
            return;
        }
    }
}

// this is when a student lines up in the back of the line; it calls attendStudent() if any windows are open
void Office::lineUp(Customer *student) {
    student->lineUp();
    line->add(student);
    cout << "Size of Line for " << type << " is " << line->size() << endl;
    if (occupWindows < maxWindows) {
        attendStudent();
    }
    cout << "Size of Line for " << type << " is " << line->size() << endl;

}

// need to fix it so that ServiceCenter.cpp can take a Customer *student from Office.cpp 
void Office::passTime() {
    for (int i = 0; i < office->getSize(); i++) {
        office->get(i)->passTime();
        if (office->get(i)->getStudent()->isDone()) {
            finished->add(office->get(i)->getStudent());
        }
        if (!office->get(i)->isOccupied() && !line->isEmpty()) {
            office->get(i)->setStudent(line->remove());
        }
    }
}

double Office::getMeanWait() {
    Window *window;
    int total = 0;
    cout << "Number of Students: " << numStudents << endl;
    for (int i = 0; i < office->getSize(); i++) {
        total += office->get(i)->getTotalWait();
    }
    return total / numStudents;
}

int Office::getLongestWait() {
    Window *window;
    int longest = 0;
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