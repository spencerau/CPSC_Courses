// Office - models an individual office in the service center

#ifndef OFFICE_H
#define OFFICE_H

#include <cstdlib>
#include <iostream>
#include "Window.h"

using namespace std;

class Office {
public:
    Office(int size, char type);
    ~Office();
    void attendStudent();
    void passTime();
    void lineUp(Customer *student);
    Customer* getAttending();
    //bool getOccupied();
private:
    char type;
    int maxWindows;
    int occupWindows;
    bool occupied;

    ListQueue<Customer*> *line;
    ListQueue<Customer*> *attending;
    ListQueue<Window*> *office;
};

#endif