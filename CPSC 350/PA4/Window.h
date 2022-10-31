// Window - models a single window in one of the offices

#ifndef WINDOW_H
#define WINDOW_H

#include <cstdlib>
#include <iostream>
#include "ListQueue.h"
#include "Customer.h"

using namespace std;

class Window {
public:
    Window(char type);
    ~Window();
    void setStudent(Customer *student);
    Customer* getStudent();
    int getTotalWait();
    int getLongest();
    int getIdle();
    bool isOccupied();
    void finish();
    void passTime();
    bool finished;
private:
    char type;
    int students;
    int totalWait;
    int idle;
    int currWait;
    int longest;
    bool occupied;

    int currTime;
    int timeNeeded;

    Customer *curStudent;
};

#endif