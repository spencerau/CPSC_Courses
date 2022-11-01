/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA4

Header File for ServiceCenter that represents a Service Center with 3 Offices


Functions:
ServiceCenter(string filename) - Constructor that takes an input filename and initializes variables, calls readFile(filename)
~ServiceCenter() - Destructor

void readFile(string filename) - Function that handles File I/O for reading from the txt file. It creates 3 Offices with respective amount of 
Windows from the first 3 lines, and then calls passTime() for the target time, stores the amount of students that are going to be arriving, and 
calls readLine(line) based on number of students that creates a new Customer, and calls Office.lineUp(student) for the respective office. It will call
passTime() until all students have finished.

void passTime() - Simulates a single minute passing in the Service Center. Calls passTime() on each of the 3 offices, and if any of the offices have
finished students, it pops the student, and if the student has offices left to go to, it calls Office.lineUp() at the respective office, else if the 
student is fully finished, then it adds the studet to finished

Customer* readLine(string line) - Takes a string line and returns a Customer created from that line; Format: time1 time2 time3 office1 office2 office3

void printMeanWait()- Prints the mean student wait time for each office by calling Office.getMeanWait()
void printLongestWait() -Prints the longest student wait time for each office by calling Office.getLongestWait()
void printWaitOver10() - Prints the number of students waiting over 10 minutes total across all offices by iterating through finished
void printMeanIdle() - Prints the mean window idle time for each office by calling Office.getMeanIdle()
void printLongestIdle() - Prints the longest window idle time for each office by calling Office.getLongestIdle()
void printIdleOver5() - Prints the number of windows idle for over 5 minutes across all offices by calling Office.getIdleOver5()

void printResult() - Function that prints out the 6 above functions to display

void printFinished() - Print Function that prints out the finished ListQ of students 
void printNewLine() - Prints out a Line to separate output

Variables:
Office *cashier - cashier's office
Office *finAid - financial aid office
Office *registrar - registrar office
int numStudents - number of students that have been read from txt file

ListQueue<Customer*> *studentLine - line of students read into from the txt file
DblList<Customer*> *finished - ListQ of students who are fully finished

int time - current time at the simulation

*/

#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include <iostream>
#include "Office.h"
#include <fstream>
#include "Office.h"

using namespace std;

class ServiceCenter {
public:
    ServiceCenter(string filename);
    ~ServiceCenter();
    void readFile(string filename);
    void passTime();
    Customer* readLine(string line);
    
    void printResult();
    void printNewLine();

    void printMeanWait();
    void printLongestWait();
    void printWaitOver10();
    void printMeanIdle();
    void printLongestIdle();
    void printIdleOver5();

    void printFinished();
private:
    Office *cashier;
    Office *finAid;
    Office *registrar;
    int numStudents;

    ListQueue<Customer*> *studentLine;
    DblList<Customer*> *finished;

    int time;
};

#endif