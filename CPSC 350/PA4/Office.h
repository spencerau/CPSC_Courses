// Office - models an individual office in the service center

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
    DblList<Window*>* getOffice();
    ListQueue<Customer*>* getFinished();
    
private:
    char type;
    int totalIdle;
    int maxWindows;
    int occupWindows;
    int totalWait;
    int numStudents;

    ListQueue<Customer*> *line;
    ListQueue<Customer*> *finished;
    DblList<Window*> *office;
};

#endif