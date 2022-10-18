// Office - models an individual office in the service center

#ifndef OFFICE_H
#define OFFICE_H

#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "Office.h"

using namespace std;

class Office {
public:
    Office(int size, char type);
    ~Office();
    void passTime();
private:
    ListQueue<Window> *office;
    char type;
};

Office::Office(int size, char type) {
    this->type = type;
    for (int i = 0; i < size; i++) {
        Window window(type);//= new Window(type);
        office->add(window);
    }
}

Office::~Office() {
    delete office;
}

void Office::passTime() {
    for (int i = 0; i < office->size(); i++) {
        //Windo
    }
}

#endif