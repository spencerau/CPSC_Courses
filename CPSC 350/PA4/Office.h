/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA4

Header File for Office that models an individual office in the service center


Functions:
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

Variables:
char type - represents the type of office
double totalIdle - total time all windows in office have been idle
int maxWindows - num of windows in the office
int occupWindows - num of windows occupied
double totalWait - total time every student that has been attended has been waiting
int numStudents - num of students that have been attended
int longestWait - longest time a student has been waiting

ListQueue<Customer*> *line - represents that line for the office
ListQueue<Customer*> *finished - students that have finished
DblList<Window*> *office - represents the office with a ListQ of Windows
*/

#ifndef OFFICE_H
#define OFFICE_H

#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "DblList.h"

using namespace std;

class Office {
public:
    Office(int size, char type);
    ~Office();
    void attendStudent();
    void passTime();
    void lineUp(Customer *student);
    Customer* getAttending();
    double getMeanWait();
    int getLongestWait();
    double getMeanIdle();
    int getLongestIdle();
    int getIdleOver5();
    DblList<Window*>*& getOffice();
    ListQueue<Customer*>*& getFinished();

    void printWindows();
    void printFinishedList();
    
private:
    char type;
    double totalIdle;
    int maxWindows;
    int occupWindows;
    double totalWait;
    int numStudents;
    int longestWait;

    ListQueue<Customer*> *line;
    ListQueue<Customer*> *finished;
    DblList<Window*> *office;
};

#endif