/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA4

CPP File for Office that models an individual office in the service center


Office(int size, char type)- Constructor that takes an int size representing the number of windows and a char type that is the type of office and 
intializes other variables

~Office() - Deconstructor

void attendStudent() - simulates when a student goes to the window to be attended; it increments occupWindows, and adds the current wait of 
student to totalWait. It then checks updates longestWait if applicable. Then it iterates through the office DBL of windows to call setStudent() to
add the student to a window

void passTime() - Simulates a single min passing in the Office. Iterates through the Windows in *office, and if there are any students in line, it
pops the student and adds it to that window. If the window is finished with the student, then it adds that student to the finished ListQ and sets 
Window.finished to false 

void lineUp(Customer *student) - takes a student parameter and simulates when a student lines up in the back of the line; it calls attendStudent() 
if any windows are open and increments numStudents

double getMeanWait() - returns totalWait / numStudents
int getLongestWait() - accessor for longestWait
double getMeanIdle() - returns the average idle time for the office
int getLongestIdle() - returns the longest idle time for a single window for the office
int getIdleOver5() - returns the amount of windows that have been idle over 5 min

DblList<Window*>*& getOffice() - returns a pointer to the current office
ListQueue<Customer*>*& getFinished() - returns the finished ListQ which is the students that are finished at this office

void printWindows() - debugging function that prints out the windows in the office
void printFinishedList() - debugging function that prints out the finished ListQ
*/

#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "Office.h"

using namespace std;

/*
Office(int size, char type)- Constructor that takes an int size representing the number of windows and a char type that is the type of office and 
intializes other variables
*/
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

ListQueue<Customer*>*& Office::getFinished() {
    return finished;
}

//void printFinishedList() - debugging function that prints out the finished ListQ
void Office::printFinishedList() {
    if (finished->isEmpty()) cout << "Finished is Empty" << endl;
    else {
        cout << "Finished List" << endl;
        for (int i = 0; i < finished->size(); i++) {
            cout << "Index " << i << ": Student" << endl;
        }
    }
}

//void printWindows() - debugging function that prints out the windows in the office
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

/*
void attendStudent() - simulates when a student goes to the window to be attended; it increments occupWindows, and adds the current wait of 
student to totalWait. It then checks updates longestWait if applicable. Then it iterates through the office DBL of windows to call setStudent() to
add the student to a window
*/
void Office::attendStudent() {
    if (occupWindows == maxWindows) return;
    occupWindows++;
    totalWait += line->peek()->getCurWait();
    if (line->peek()->getCurWait() > longestWait) {
        longestWait = line->peek()->getCurWait();
    }
    for (int i = 0; i < office->getSize(); i++) {
        if (!office->get(i)->isOccupied()) {
            office->get(i)->setStudent(line->remove());
            return;
        }
    }
}

/*
void lineUp(Customer *student) - takes a student parameter and simulates when a student lines up in the back of the line; it calls attendStudent() 
if any windows are open and increments numStudents
*/
void Office::lineUp(Customer *student) {
    line->add(student);
    if (occupWindows < maxWindows) {
        attendStudent();
    }
    numStudents++;
}

/*
void passTime() - Simulates a single min passing in the Office. Iterates through the Windows in *office, and if there are any students in line, it
pops the student and adds it to that window. If the window is finished with the student, then it adds that student to the finished ListQ and sets 
Window.finished to false 
*/
void Office::passTime() {
    for (int i = 0; i < office->getSize(); i++) {
        office->get(i)->passTime();
        if (!office->get(i)->isOccupied()) {
            if (!line->isEmpty()) {
                office->get(i)->setStudent(line->remove());
            }
            if (office->get(i)->finished) {
                finished->add(office->get(i)->getStudent());
                office->get(i)->finished = false;
            }
        }
    }
}

/*
double getMeanWait() - returns totalWait / numStudents
*/
double Office::getMeanWait() {
    return totalWait / numStudents;
}

/*
int getLongestWait() - returns longestWait
*/
int Office::getLongestWait() {
    return longestWait;
}

/*
double getMeanIdle() - returns the average idle time for the office
*/
double Office::getMeanIdle() {
    double total = 0;
    for (int i = 0; i < office->getSize(); i++) {
        total += office->get(i)->getIdle();
    }
    return total / maxWindows;
}

/*
int getLongestIdle() - returns the longest idle time for a single window for the office
*/
int Office::getLongestIdle() {
    double max = 0;
    for (int i = 0; i < office->getSize(); i++) {
        if (office->get(i)->getIdle() > max) {
            max = office->get(i)->getIdle();
        }
    }
    return max;
}

/*
int getIdleOver5() - returns the amount of windows that have been idle over 5 min
*/
int Office::getIdleOver5() {
    int idleOver5 = 0;
    for (int i = 0; i < office->getSize(); i++) {
        if (office->get(i)->getIdle() >= 5) idleOver5++;
    }
    return idleOver5;
}