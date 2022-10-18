// Window - models a single window in one of the offices

#ifndef WINDOW_H
#define WINDOW_H

#include <cstdlib>
#include <iostream>
#include "ListQueue.h"
#include "Customer.h"
#include "Window.h"
using namespace std;

class Window {
public:
    Window(char type);
    ~Window();
    void enqueue(Customer student);
    void dequeue();
    void passTime();
    double getAvg();
private:
    int students;
    int totalTime;
    int idle;
    int currWait;
    char type;

    ListQueue<Customer> *queue;
};

#endif