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

void Office::printFinishedList() {
    if (finished->isEmpty()) cout << "Finished is Empty" << endl;
    else {
        for (int i = 0; i < finished->size(); i++) {
            cout << "Index " << i << ": Student" << endl;
        }
    }
}

void Office::printWindows() {
    //cout << "The office is " << type << endl;
    int occupied = 0;
    //cout << "Size of the Office is " << office->getSize() << endl;
    for (int i = 0; i < office->getSize(); i++) {
        //cout << "Window " << i;
        if (office->get(i)->isOccupied()) {
            //cout << " has a Student" << endl;
            occupied++;
        }
        //else cout << " is sitting on their ass playing with their dicks" << endl;
    }
    //cout << occupied << " Windows are currently occupied" << endl;
    //cout << "---------------------------------------------------------" << endl;
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
    //cout << "Size of Line for " << type << " is " << line->size() << endl;
    if (occupWindows < maxWindows) {
        attendStudent();
    }
    //cout << "Size of Line for " << type << " is " << line->size() << endl;

}

// need to fix it so that ServiceCenter.cpp can take a Customer *student from Office.cpp 
void Office::passTime() {
    for (int i = 0; i < office->getSize(); i++) {
        cout << endl; 
        cout << "Currently at Window " << i << " in Office " << type <<endl;
        //cout << "Window " << i << " before passTime()" << endl;
        office->get(i)->passTime();
        //cout << "Window " << i << " passTime() worked" << endl;

        //cout << "Student was added to this window" << endl;
        if (office->get(i)->isOccupied()) {
            //cout << "Before checking if line is empty" << endl;
            if (!line->isEmpty()) {
                //cout << "Before setStudent()" << endl;
                office->get(i)->setStudent(line->remove());
                //cout << "Student successfulled attended at Window " << i << endl;
            }
            // this bracket is causing a seg fault
            if (office->get(i)->getStudent()->isFinished()) {
                cout << "student is finished" << endl;
                finished->add(office->get(i)->getStudent());
            }
        }
        //cout << "Finished at Window " << i << endl;
    }
    cout << endl;
    cout << "Office " << type << " has successfully passed 1 min" << endl;
    printFinishedList();
    cout << "---------------------------------------------------------------------" << endl;
}

double Office::getMeanWait() {
    Window *window;
    int total = 0;
    //cout << "Number of Students: " << numStudents << endl;
    printWindows();
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