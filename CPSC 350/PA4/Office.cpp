// Office - models an individual office in the service center

#include <cstdlib>
#include <iostream>
#include "Window.h"
#include "Office.h"

using namespace std;

Office::Office(int size, char type) {
    this->type = type;
    for (int i = 0; i < size; i++) {
        Window window(type);//= new Window(type);
        office->add(window);
    }
    maxWindows = size;
    occupWindows = 0;
}

Office::~Office() {
    delete office;
}

void Office::passTime() {
    for (int i = 0; i < office->size(); i++) {
        //Windo
    }
}