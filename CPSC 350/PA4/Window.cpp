// Window - models a single window in one of the offices

#include <cstdlib>
#include <iostream>
#include "ListQueue.h"
#include "Customer.h"
#include "Window.h"

using namespace std;

Window::Window(char type) {
    this->students = 0;
    this->totalTime = 0;
    this->idle = 0;
    this->currWait = 0;
    this->type = type;
    this->queue = new ListQueue<Customer>();
}

Window::~Window() {
    delete queue;
}

void Window::enqueue(Customer student) {
    queue->add(student);
    currWait = 0;
}

void Window::dequeue() {
    students++;
    totalTime += queue->peek().getWait();
    queue->remove();
    currWait = 0;
}

void Window::passTime() {
    if (queue->isEmpty()) idle++;
    else {
        currWait++;
        for (int i = 0; i < queue->size(); i++) {
            Customer student = queue->peek();
            student.passTime();
            student = student.getNext();
        }
        switch (type) {
            case 'f':
                if (currWait >= queue->peek().getFinAid()) dequeue();
                break;
            case 'r':
                if (currWait >= queue->peek().getRegist()) dequeue();
                break;
            case 'c':
                if (currWait >= queue->peek().getCash()) dequeue();
                break;
        }
    }
}

double Window::getAvg() {
    return totalTime / students;
}

