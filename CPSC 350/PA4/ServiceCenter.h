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