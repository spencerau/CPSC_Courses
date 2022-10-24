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
    //void enqueue(Customer student);
    //void dequeue();
    bool passTime();
    double getAvg();
    void setStudent(Customer *student);
private:
    char type;
    int students;
    int totalTime;
    int idle;
    int currWait;
    int timeNeeded;
    bool occupied;

    Customer *currentStudent;
};

#endif